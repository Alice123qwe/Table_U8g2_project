/*** 
 * @Author: Aliceee 1197346248@qq.com
 * @Date: 2024-01-23 01:17:01
 * @LastEditors: Aliceee 1197346248@qq.com
 * @LastEditTime: 2024-01-23 01:49:11
 * @FilePath: \Table_project\components\AXP2101\inc\Self_AXP2101.h
 * @Description: 
 * @_(:3」∠)_ 只想当一个单纯的笨蛋        ---最上川
 * @Copyright (c) 2024 by Aliceee, All Rights Reserved. 
 */
#ifndef _Self_AXP2101
#define _Self_AXP2101
#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "freertos/queue.h"




#define PMU_INPUT_PIN    (gpio_num_t)2 /*!< axp power chip interrupt Pin*/

#define XPOWERS_CHIP_AXP2101
#include"XPowersLib.h"

void AXP2101_Init(void);

extern esp_err_t pmu_init();
extern esp_err_t i2c_init(void);


#endif