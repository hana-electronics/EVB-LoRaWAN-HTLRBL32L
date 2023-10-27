
#include "main.h"

#ifndef ADC_ADCSETUP_H_
#define ADC_ADCSETUP_H_

#define USER_DATAWIDTH        (ADC_DS_DATA_WIDTH_16_BIT)
#define USER_RATIO            (ADC_DS_RATIO_128)

#define USER_SAMPLERATE       (ADC_SAMPLE_RATE_28)

#define PRINT_INT(x)    ((int)(x))
#define PRINT_FLOAT(x)  (x>0)? ((int) (((x) - PRINT_INT(x)) * 100)) : (-1*(((int) (((x) - PRINT_INT(x)) * 100))))
#define PRINT_FLOAToneDecimal(x)  (x>0)? ((int) (((x) - PRINT_INT(x)) * 10)) : (-1*(((int) (((x) - PRINT_INT(x)) * 10))))

#ifndef HAL_ADC_MODULE_ENABLED // This is defined in "bluenrg_lp_hal_conf.h"
#define HAL_ADC_MODULE_ENABLED
#endif

#define PB3_CHANNEL		(ADC_CH_VINP0_TO_SINGLE_POSITIVE_INPUT) //for PB3
#define PB2_CHANNEL		(ADC_CH_VINM0_TO_SINGLE_NEGATIVE_INPUT) //for PB2
#define PB1_CHANNEL		(ADC_CH_VINP1_TO_SINGLE_POSITIVE_INPUT) //for PB1
#define PB0_CHANNEL		(ADC_CH_VINM1_TO_SINGLE_NEGATIVE_INPUT) //for PB0
#define PA15_CHANNEL	(ADC_CH_VINP2_TO_SINGLE_POSITIVE_INPUT) //for PA15
#define PA12_CHANNEL	(ADC_CH_VINM3_TO_SINGLE_NEGATIVE_INPUT) //for PA12

void adc_config_INIT(void);
float batt_measure(void);
float cpu_temp_measure(void);
//float pin_voltage_measure(uint8_t channel);
uint16_t pin_voltage_measure(uint8_t channel);

#endif /* ADC_ADCSETUP_H_ */
