// 1. INCLUDES (The Toolbox)
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// 2. DEFINES & CONSTANTS (Magic Numbers)
#define LED_PIN 2
static const char *TAG = "MY_APP"; // The name that appears in logs

// 3. MAIN FUNCTION (The Entry Point)
void app_main(void)
{
    // A. Configuration (Run once)
    ESP_LOGI(TAG, "System Initializing...");
    
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // B. The Loop (Run forever)
    while (1) {
        ESP_LOGI(TAG, "Turning LED ON");
        gpio_set_level(LED_PIN, 1);
        
        // Blocking Delay (1 second)
        vTaskDelay(pdMS_TO_TICKS(1000));

        ESP_LOGI(TAG, "Turning LED OFF");
        gpio_set_level(LED_PIN, 0);
        
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}