idf_component_register(SRCS "mqtt_handler.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_netif esp_event nvs_flash mqtt
                    )
                    component_compile_options(-Wno-error=format= -Wno-format)