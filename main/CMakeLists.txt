
set(COMPONENT_REQUIRES)
set(COMPONENT_PRIV_REQUIRES)
set(COMPONENT_SRCS "iot-farm.c ../components/esp_cron/cron.c ../components/esp_cron/library/jobs/jobs.c ../components/esp_cron/library/ccronexpr/ccronexpr.c ../components/esp_cron/library/timegm/timegm.c")
set(COMPONENT_ADD_INCLUDEDIRS "../components/esp_cron ../components/esp_cron/include ../components/esp_cron/library/ccronexpr ../components/esp_cron/library/jobs")
register_component()

# Create a SPIFFS image from the contents of the 'spiffs_image' directory
# that fits the partition named 'storage'. FLASH_IN_PROJECT indicates that
# the generated image should be flashed when the entire project is flashed to
# the target with 'idf.py -p PORT flash'.
spiffs_create_partition_image(storage ../spiffs_image FLASH_IN_PROJECT)