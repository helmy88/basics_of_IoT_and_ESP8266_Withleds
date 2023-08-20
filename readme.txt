# ESP8266 LED State Simulation and ThingSpeak Integration

This project demonstrates how to use an ESP8266 microcontroller to simulate different LED states and send the simulated data to ThingSpeak, an Internet of Things (IoT) platform for data visualization and analysis. The project utilizes the Arduino framework for programming the ESP8266 and involves connecting LEDs to represent different states, connecting to Wi-Fi, and making HTTP requests to update a ThingSpeak channel.

## Prerequisites

1. **ESP8266 Board**: You'll need an ESP8266 development board (e.g., NodeMCU) to run the code.

2. **Arduino IDE**: Install the Arduino IDE to upload the code to your ESP8266.

3. **ESP8266 Library**: Install the ESP8266 board support in the Arduino IDE. Instructions can be found here: https://github.com/esp8266/Arduino#installing-with-boards-manager

4. **ThingSpeak Account**: Sign up for a ThingSpeak account at https://thingspeak.com/

## Getting Started

1. Clone this repository or download the ZIP file and extract its contents.

2. Open the `esp8266_thingspeak_led.ino` file in the Arduino IDE.

3. Replace placeholders with actual values:
   - Replace `your_wifi_ssid` with your Wi-Fi network name (SSID).
   - Replace `your_wifi_password` with your Wi-Fi password.
   - Replace `your_thingspeak_api_key` with your ThingSpeak Write API Key.

4. Connect your LEDs to the defined GPIO pins in the code.

5. Upload the modified code to your ESP8266 board as described in the Arduino IDE.

6. Open the Serial Monitor to view ESP8266 status and IP address.

7. The LEDs will simulate different states, and the data will be sent to ThingSpeak for visualization.

## ThingSpeak Integration

1. Sign in to your ThingSpeak account or create a new account if needed.

2. Create a new ThingSpeak channel and configure it with the desired field labels.

3. Note down the Write API Key for your channel.

4. Replace the `your_thingspeak_api_key` placeholder in the code with your ThingSpeak Write API Key.

5. The ESP8266 will send data to ThingSpeak, and you can monitor the channel graphs and data on your ThingSpeak dashboard.

## Contributing

Feel free to contribute to this project by suggesting improvements, reporting issues, or adding new features.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
