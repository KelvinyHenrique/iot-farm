idf_component_register(SRCS "wifi_manager.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_netif esp_event nvs_flash esp_wifi)
