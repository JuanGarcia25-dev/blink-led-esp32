#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"

#define BLINK_GPIO 2

void app_main(void)
{
    printf("Ejemplo: Blink LED en ESP32 (GPIO%d)\n", BLINK_GPIO);

    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(BLINK_GPIO, 1);
        printf("LED ON\n");
        vTaskDelay(pdMS_TO_TICKS(1000));

        gpio_set_level(BLINK_GPIO, 0);
        printf("LED OFF\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
