void mqtt_start(void);

int mqtt_publish(const char *topic, const char *data, int len, int qos, int retain);

int mqtt_subscribe(const char *topic, int qos);

int mqtt_unsubscribe(const char *topic);

void mqtt_stop(void);

void mqtt_destroy(void);

void mqtt_restart(void);