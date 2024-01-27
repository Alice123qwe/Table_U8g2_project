/*** 
 * @Author: Aliceee 1197346248@qq.com
 * @Date: 2024-01-19 21:49:48
 * @LastEditors: Aliceee 1197346248@qq.com
 * @LastEditTime: 2024-01-24 18:17:38
 * @FilePath: \Table_project\components\OLED\inc\oled.h
 * @Description: 
 * @_(:3」∠)_ 只想当一个单纯的笨蛋        ---最上川
 * @Copyright (c) 2024 by Aliceee, All Rights Reserved. 
 */
#ifndef __OLED_H_
#define __OLED_H_

//-----------include------------------------------------
#include "u8g2.h"
#include "u8x8.h"
#include "esp_rom_sys.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/portmacro.h" //portTICK_PERIOD_MS

//-----------PIN_define----------------------------------
#define OLED_SCL 6
#define OLED_SDA 7

//-----------Function declaration------------------------
void oled_init(void);
void oled_test(void);
void test(void);

#endif
