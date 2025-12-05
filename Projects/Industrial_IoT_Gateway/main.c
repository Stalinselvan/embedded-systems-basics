#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_random.h"

static const char *TAG = "GATEWAY_CORE";

// Data Structure
typedef struct {
    float temperature;
    float humidity;
    uint8_t sensor_id;
} SensorData_t;

// Fake Sensor Driver
SensorData_t read_fake_sensor() {
    SensorData_t data;
    data.temperature = 20.0 + (esp_random() % 100) / 10.0;
    data.humidity = 40.0 + (esp_random() % 200) / 10.0;
    data.sensor_id = 1;
    return data;
}

void app_main(void) {
    ESP_LOGI(TAG, "Booting Industrial IoT Gateway...");

    while (1) {
        SensorData_t reading = read_fake_sensor();
        
        ESP_LOGI(TAG, "Reading - ID: %d | Temp: %.2f C", 
                 reading.sensor_id, reading.temperature);
        
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}