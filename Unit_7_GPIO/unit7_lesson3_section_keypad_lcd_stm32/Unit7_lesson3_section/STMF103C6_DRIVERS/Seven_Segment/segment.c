/*
 * segment.c
 *
 *  Created on: Mar 7, 2024
 *      Author: hassa
 */

#include "segment.h"

GPIO_PinConfig_t segment_config;

void Segement_Init(void)
{
	segment_config.GPIO_PinNumber = GPIO_PINS_9;
	segment_config.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	segment_config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(Segment_Port, &segment_config);

	segment_config.GPIO_PinNumber = GPIO_PINS_10;
	segment_config.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	segment_config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(Segment_Port, &segment_config);

	segment_config.GPIO_PinNumber = GPIO_PINS_11;
	segment_config.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	segment_config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(Segment_Port, &segment_config);

	segment_config.GPIO_PinNumber = GPIO_PINS_12;
	segment_config.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	segment_config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(Segment_Port, &segment_config);

	segment_config.GPIO_PinNumber = GPIO_PINS_13;
	segment_config.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	segment_config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(Segment_Port, &segment_config);

	segment_config.GPIO_PinNumber = GPIO_PINS_14;
	segment_config.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	segment_config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(Segment_Port, &segment_config);

	segment_config.GPIO_PinNumber = GPIO_PINS_15;
	segment_config.GPIO_Pin_Config = GPIO_CONFIG_Output_PP;
	segment_config.GPIO_Mode_config = GPIO_MODE_Output_10MHz;
	MCAL_GPIO_INIT(Segment_Port, &segment_config);
}
