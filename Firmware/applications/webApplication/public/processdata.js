var socket = io();

socket.on("SEND_DATA",function(data) { 
	document.getElementById('displayTTNData').innerHTML = data;
});

function requestGetDataAfterATime() {
    socket.emit("REQUEST_GET_DATA");
}
