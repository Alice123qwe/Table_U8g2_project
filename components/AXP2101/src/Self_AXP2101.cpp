/*** 
 * @Author: Aliceee 1197346248@qq.com
 * @Date: 2024-01-23 01:18:02
 * @LastEditors: Aliceee 1197346248@qq.com
 * @LastEditTime: 2024-01-23 02:18:02
 * @FilePath: \Table_project\components\AXP2101\src\Self_AXP2101.cpp
 * @Description: 
 * @_(:3」∠)_ 只想当一个单纯的笨蛋        ---最上川
 * @Copyright (c) 2024 by Aliceee, All Rights Reserved. 
 */
#include "Self_AXP2101.h"
//irs处理函数
static void IRAM_ATTR pmu_irq_handler(void *arg)
{

}

void irq_init()
{
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_NEGEDGE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = BIT64(PMU_INPUT_PIN);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
    gpio_set_intr_type(PMU_INPUT_PIN, GPIO_INTR_NEGEDGE);
    //install gpio isr service
    gpio_install_isr_service(0);
    //hook isr handler for specific gpio pin
    gpio_isr_handler_add(PMU_INPUT_PIN, pmu_irq_handler, (void *) PMU_INPUT_PIN);
}

void AXP2101_Init(){
    irq_init();
    ESP_ERROR_CHECK(i2c_init());
    ESP_ERROR_CHECK(pmu_init());
}
