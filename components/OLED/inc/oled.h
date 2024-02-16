/*** 
 * @Author: Aliceee 1197346248@qq.com
 * @Date: 2024-01-19 21:49:48
 * @LastEditors: Aliceee 1197346248@qq.com
 * @LastEditTime: 2024-02-16 09:27:40
 * @FilePath: \Table_U8g2_project\components\OLED\inc\oled.h
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

#include "pic.h"

//-----------PIN_define----------------------------------
#define OLED_SCL 6
#define OLED_SDA 7

//-----------Function declaration------------------------
void oled_init(void);
void oled_test(void);
void draw_logo(u8g2_uint_t x,u8g2_uint_t y);

#endif
