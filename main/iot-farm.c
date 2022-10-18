#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "wifi_manager.h"

static const char *TAG_FIRM = "iot-farm";
void app_main(void)
{
    connect();
    while (1)
    {
        ESP_LOGI(TAG_FIRM, "Hello world!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
