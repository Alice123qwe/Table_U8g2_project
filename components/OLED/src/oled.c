/***
 * @Author: Aliceee 1197346248@qq.com
 * @Date: 2024-01-19 21:49:38
 * @LastEditors: Aliceee 1197346248@qq.com
 * @LastEditTime: 2024-01-19 22:28:34
 * @FilePath: \Table_project\main\oled.c
 * @Description:
 * @_(:3」∠)_ 只想当一个单纯的笨蛋        ---最上川
 * @Copyright (c) 2024 by Aliceee, All Rights Reserved.
 */

#include "oled.h"


u8g2_t u8g2;


void oled_init()
{
    u8g2Init(&u8g2);
}

void oled_test()
{
    for (int i = 0; i < 84; i++)
    {
    u8g2_ClearBuffer(&u8g2);
    //u8g2_SendBuffer(&u8g2); 
    u8g2_SetFont(&u8g2, u8g2_font_10x20_me); // 设置英文字体
    u8g2_DrawStr(&u8g2, 1, i, "hello world");
    u8g2_SendBuffer(&u8g2); // 一定要发送buffer
    vTaskDelay(5 / portTICK_PERIOD_MS); // 延时5ms
    }
    
    
}