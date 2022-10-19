#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "wifi_manager.h"
#include "time.h"
#include "esp_sntp.h"

static const char *TAG_FIRM = "iot-farm";
void app_main(void)
{
    connect();
    //################################ Time #################################

    ESP_LOGI(TAG_FIRM, "Setting clock...");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);
    sntp_setservername(0, "pool.ntp.org");
    sntp_init();
    while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET)
    {
        ESP_LOGI(TAG_FIRM, "Waiting for system time to be set...");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }

    ESP_LOGI(TAG_FIRM, "Setting time zone...");
    setenv("TZ", "<-03>3", 1);
    tzset();
    while (1)
    {
        ESP_LOGI(TAG_FIRM, "Hello world!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
