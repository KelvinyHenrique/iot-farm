#include <stdio.h>

void app_main(void)
{
    printf("Hello world!");

    while (1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
