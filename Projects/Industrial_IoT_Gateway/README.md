# Industrial IoT Gateway (ESP32)

## Status: 🟡 In Development

## Project Goal
To build a fault-tolerant IoT Gateway that reads sensor data, buffers it locally in RAM (using a Ring Buffer) to handle network disconnects, and uploads it to the cloud via MQTT.

## Technical Implementation
* **Hardware:** ESP32 DevKit V1
* **RTOS:** FreeRTOS (Tasks & Queues)
* **Driver:** Custom Simulated Sensor Driver