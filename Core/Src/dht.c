/*
 * dht.c
 *
 *  Created on: Nov 13, 2019
 *      Author: huseyn
 */

#include "micros.h"


void dht22_measure()
{
	DWT_Init();

	// communication started
	HAL_GPIO_WritePin(DHT22_GPIO_Port, DHT22_Pin, GPIO_PIN_RESET);
	HAL_Delay(2);

	while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) == GPIO_PIN_RESET);
	delay_micros(40);

	while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) ==  GPIO_PIN_SET);
	delay_micros(80);

	while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) == GPIO_PIN_RESET);
	delay_micros(80);

	//preparation complete

	int data[40] = { 0 };

	for (int i = 0; i < 40; ++i)
	{
		int counter = 0;

		while( HAL_GPIO_ReadPin(DHT22_GPIO_Port,DHT22_Pin) != GPIO_PIN_SET)
		{
		}

		delay_micros(50);

		while (HAL_GPIO_ReadPin(DHT22_GPIO_Port, DHT22_Pin) == GPIO_PIN_SET)
		{
			counter ++;
		}

		data[i] = counter;

	}

	int max = data[0];
	for ( int i = 0; i < 40; ++i)
	{
		if (data[i] > max)
			max = data[i];
    }

//	for (int i = 0; i < )
}










