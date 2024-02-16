/***
 * @Author: Aliceee 1197346248@qq.com
 * @Date: 2024-01-19 21:22:13
 * @LastEditors: Aliceee 1197346248@qq.com
 * @LastEditTime: 2024-01-19 22:44:21
 * @FilePath: \Table_project\main\main.c
 * @Description:
 * @_(:3」∠)_ 只想当一个单纯的笨蛋        ---最上川
 * @Copyright (c) 2024 by Aliceee, All Rights Reserved.
 */
//-------------------------------------------------------------

//SDA是7脚,SCL是6脚,自己淘宝上随便找个ssd1306 128*64的练练手

//-------------------------------------------------------------

#include "stdio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/portmacro.h" //portTICK_PERIOD_MS
#include "freertos/semphr.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "u8g2.h"
#include "u8x8.h"
//-----------Add by Aliceee------------------------------------
#include"Self_AXP2101.h"
extern "C" {
#include "oled.h"
#include "Self_config.h"
}
//-------------------------------------------------------------
TaskHandle_t Init_Task_h;
UBaseType_t id = 0;

void Init_Task(void *arg)
{
    printf("Init_Start\n");
    if(Have_AXP2101) AXP2101_Init();//你没有PMU就把去config里把变量搞成flase就行
    ESP_ERROR_CHECK(nvs_flash_init());
    oled_init();
    printf("Init_End\n");
    vTaskDelete(Init_Task_h);
}
TaskHandle_t Task_Task_h;
void Test_Task(void *arg)
{
    printf("Test_Start\n");
    while (1)
    {
        oled_test();
    }
}

extern"C"{
    void app_main(void)
{
    xTaskCreate(Init_Task, "Init", 1024 * 100, NULL, 1, &Init_Task_h);
    vTaskDelay(5000 / portTICK_PERIOD_MS); // 延时10s
    xTaskCreate(Test_Task, "Test", 1024 * 100, NULL, 1, &Task_Task_h);
}
}

