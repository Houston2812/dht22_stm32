/*
 * dht.c
 *
 *  Created on: Nov 13, 2019
 *      Author: huseyn
 */

#include "micros.h"

int data[40] = { 0 };

void dht22_measure()
{
	DWT_Init();

	// communication started
	HAL_GPIO_WritePin(DHT22_GPIO_Port, DHT22_Pin, GPIO_PIN_RESET);
	HAL_Delay(2);

	HAL_GPIO_WritePin(DHT22_GPIO_Port, DHT22_Pin, GPIO_PIN_SET);
	delay_micros(30);

	while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) == GPIO_PIN_SET);

	while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) ==  GPIO_PIN_RESET);

	while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) == GPIO_PIN_SET);

	//preparation complete


	for (int i = 0; i < 40; ++i)
	{

		while( HAL_GPIO_ReadPin(DHT22_GPIO_Port,DHT22_Pin) != GPIO_PIN_SET)
		{
		}

		while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) == GPIO_PIN_SET)
		{
			delay_micros(30);
			if (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) == GPIO_PIN_SET)
				data[i] = 1;

			else
				data[i] = 0;

			break;

		}

	}

}










