# Light Sensor LED Control (Assembly)

An automatic light control project written in **8051 Assembly**. A light sensor (LDR module) detects the surrounding brightness, and the microcontroller turns an LED **ON in the dark** and **OFF in the light**, just like a street light or night lamp.

## Features

- Automatic LED control based on ambient light
- Reads the sensor through a digital input pin
- Simple polling loop, easy to understand and modify
- Can be simulated in Proteus or run on real hardware

## Components

| Component | Quantity | Note |
|-----------|----------|------|
| 8051 microcontroller (AT89S51/AT89C51) | 1 | Main controller |
| LDR sensor module (with digital output) | 1 | Output to P1.0 |
| LED | 1 | Connected to P2.0 |
| 330 Ω resistor | 1 | Current limiting for LED |
| 11.0592 MHz crystal + 2 × 33 pF capacitors | 1 set | Clock circuit |
| 10 µF capacitor + 10 kΩ resistor | 1 set | Reset circuit |
| 5 V power supply | 1 | |

## Pin Connections

| Pin | Connected To | Description |
|-----|--------------|-------------|
| P1.0 | LDR module DO | Sensor input |
| P2.0 | LED (via resistor) | Output |
| VCC / GND | 5 V / Ground | Power |

## Project Structure

```
light-sensor-led/
├── README.md
├── light_led.asm        # Main source code
├── circuit/             # Circuit diagram / Proteus file
└── screenshots/         # Output images
```

## How It Works

1. The LDR module outputs **HIGH (1)** when it is dark and **LOW (0)** when it is bright. (This depends on your module. Check yours and swap the logic if needed.)
2. The microcontroller continuously reads pin `P1.0`.
3. If the pin is HIGH (dark), the LED on `P2.0` is turned ON.
4. If the pin is LOW (bright), the LED is turned OFF.
5. The loop repeats forever.

## Code

```asm
        ORG 0000H

SENSOR  BIT P1.0
LED     BIT P2.0

        SETB SENSOR        ; make P1.0 an input

MAIN:   JB   SENSOR, DARK  ; if sensor = 1, it is dark
        CLR  LED           ; bright: LED OFF (adjust if LED is active-low)
        SJMP MAIN

DARK:   SETB LED           ; dark: LED ON
        SJMP MAIN

        END
```

> If your LED is wired active-low (cathode to the pin), swap `SETB LED` and `CLR LED`.

## Tools

- [Keil µVision](https://www.keil.com/) for assembling and generating the HEX file
- [Proteus](https://www.labcenter.com/) for circuit simulation
- A programmer (USBasp or similar) to upload the HEX file to real hardware

## How to Run

1. Open `light_led.asm` in Keil and build it to generate `light_led.hex`.
2. In Proteus, load the HEX file into the 8051 and run the simulation.
3. Change the light level on the sensor and watch the LED respond.
4. For hardware, burn the HEX file to the chip and build the circuit as shown above.

## Troubleshooting

| Problem | Possible Fix |
|---------|--------------|
| LED works in reverse | Swap the logic or adjust the sensitivity potentiometer on the module |
| LED does not turn on | Check LED polarity and resistor |
| Flickering in dim light | Add a small delay or use the module's potentiometer to set a clear threshold |

## Future Improvements

- [ ] Add a delay/debounce to avoid flickering
- [ ] Use an ADC (ADC0804) for analog brightness levels
- [ ] PWM-based dimming of the LED
- [ ] Multiple LEDs for different brightness levels

## Author

Your Name

## License

MIT License
