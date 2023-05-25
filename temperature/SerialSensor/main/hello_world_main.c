#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "rom/ets_sys.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#include "DHT22.h"

void DHT_task(void *pvParameter)
{
	setDHTgpio( 4 );

    while(true) {
        int ret = readDHT();

        char str[50];
        sprintf(str, "%d,%.1f,%.1f\n", ret, getTemperature(), getHumidity());
        printf(str);
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
	nvs_flash_init();
	vTaskDelay( 1000 / portTICK_RATE_MS );
	xTaskCreate( &DHT_task, "DHT_task", 2048, NULL, 5, NULL );
}
