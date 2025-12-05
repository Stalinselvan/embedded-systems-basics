#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_random.h"

// 1. The Tag: This is like a "Channel Name" for your logs.
//    It helps you filter messages when you have 10 different tasks running.
static const char *TAG = "SENSOR_DRIVER";

// 2. The Struct: Defining what our "Fake Sensor" data looks like.
typedef struct {
    float temperature;
    float humidity;
    uint8_t sensor_id;
} SensorData_t;

// 3. The Driver Function: Simulates reading hardware
//    In a real driver, you would read I2C registers here.
SensorData_t read_fake_sensor() {
    SensorData_t data;
    
    // esp_random() returns a huge 32-bit random number.
    // We use modulo (%) to constrain it to a realistic range.
    data.temperature = 20.0 + (esp_random() % 100) / 10.0; // Random 20.0 - 30.0
    data.humidity = 40.0 + (esp_random() % 200) / 10.0;    // Random 40.0 - 60.0
    data.sensor_id = 1;

    return data;
}

// 4. The Main Loop (Application Entry Point)
void app_main(void)
{
    ESP_LOGI(TAG, "Starting Industrial IoT Gateway...");

    while (1) {
        // Step A: "Read" the sensor
        SensorData_t current_reading = read_fake_sensor();

        // Step B: Print the data using ESP_LOG (Not printf!)
        // '%.2f' prints 2 decimal places.
        ESP_LOGI(TAG, "Sensor ID: %d | Temp: %.2f C | Hum: %.2f %%", 
                 current_reading.sensor_id, 
                 current_reading.temperature, 
                 current_reading.humidity);

        // Step C: Delay
        // vTaskDelay is a FreeRTOS function. It pauses this task 
        // and lets the processor do other things (like handle Wi-Fi).
        // pdMS_TO_TICKS(1000) converts "1000 milliseconds" to "CPU Ticks".
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}