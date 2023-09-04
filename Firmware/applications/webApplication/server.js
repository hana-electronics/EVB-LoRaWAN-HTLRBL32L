var express = require("express");
var app = express();
app.use(express.static("public")); //Procedure to set public folder contain process files (css,image,.js,..)
app.set('view engine', 'ejs'); // Use ejs instead of html
app.set("views", "./views"); // view folder contain .ejs files

// Parse URL-encoded bodies (as sent by HTML forms)
const bodyParser = require('body-parser')
app.use(bodyParser.urlencoded({ extended: true }))

// Create server
var server = require("http").Server(app);
var io = require("socket.io")(server);

var socketp = null;

server.listen(process.env.PORT || 3000, () => {
  console.log('listening on *:3000');
});

// MQTT setup
var mqtt = require('mqtt');
var options = {
  port: 1883,
  clientId: 'mqttjs_' + Math.random().toString(16).substr(2, 8),
  username: 'lora-htapp2@ttn',
  password: 'NNSXS.VSN6UUPB5AXCS7SCTFGDUD3NOZZUZ2GP5YN7QQQ.KLF2ASLHSTLEE6KF3N22BATUZDK2GZZX5RGGPHLATGEIMRQBV6VQ',
  keepalive: 60,
  reconnectPeriod: 1000,
  protocolId: 'MQIsdp',
  protocolVersion: 3,
  clean: true,
  encoding: 'utf8'
};
var client = mqtt.connect('https://eu1.cloud.thethings.network', options);

// Global variable to save data
var globalMQTT = 0;

// SOCKET
io.on("connection", function (socket) {
  console.log("Client connected: " + socket.id);
  socketp = socket;
  socket.on("disconnect", function () {
    console.log(socket.id + " disconnected");
	socketp = null;
  });
});

// MQTT setup
client.on('connect', function () {
  console.log('Client connected to TTN')
  client.subscribe('#')
});

client.on('error', function (err) {
  console.log(err);
});

client.on('message', function (topic, message) {
  var getDataFromTTN = JSON.parse(message);
  var getFrmPayload = getDataFromTTN.uplink_message.decoded_payload?.Temperature;
  
  console.debug(getFrmPayload);
  
  if(getFrmPayload != undefined) {
	globalMQTT = getFrmPayload + 'º';
   socketp.emit("SEND_DATA", globalMQTT);
  }
});

// Setup load ejs file to display on Browsers
app.get('/lora', function (req, res) {
  res.render("dashboard");
});
