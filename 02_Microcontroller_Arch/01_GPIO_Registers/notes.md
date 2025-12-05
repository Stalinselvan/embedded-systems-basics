# GPIO Registers Notes

## Concept
In embedded systems, we don't just "turn on" a pin. We manipulate memory addresses mapped to hardware.

## Key Registers (ESP32)
* **GPIO_ENABLE_REG**: Controls whether a pin is Input or Output.
* **GPIO_OUT_REG**: Sets the voltage level (High/Low).
* **GPIO_IN_REG**: Reads the current voltage level.

## My Driver Logic
Used `gpio_reset_pin()` to disconnect the pin from other peripherals and `gpio_set_level()` to modify the output register safely.