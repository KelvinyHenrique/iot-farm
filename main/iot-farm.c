#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "wifi_manager.h"
#include "time.h"
#include "esp_sntp.h"
#include "cron.h"

static const char *TAG_FIRM = "iot-farm";

void test_cron_job_sample_callback(cron_job *job)
{
    ESP_LOGI(TAG_FIRM, "Cron job callback");
    return;
}

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

    cron_job *jobs[2];
    jobs[0] = cron_job_create("* * * * * *", test_cron_job_sample_callback, (void *)0);
    jobs[1] = cron_job_create("*/5 * * * * *", test_cron_job_sample_callback, (void *)10000);
    cron_start();
}
