#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Replace with your Wi-Fi credentials
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

// ThingSpeak details
const char* thingSpeakAddress = "api.thingspeak.com";
const char* writeAPIKey = "your_thingspeak_api_key";

// Pins connected to the LEDs
const int redLedPin = 2;    // Red LED on GPIO 2
const int greenLedPin = 3;  // Green LED on GPIO 3
const int blueLedPin = 4;   // Blue LED on GPIO 4

void setup() {
  Serial.begin(115200);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Simulate different states using LEDs
  digitalWrite(redLedPin, HIGH);     // Turn on red LED
  digitalWrite(greenLedPin, LOW);    // Turn off green LED
  digitalWrite(blueLedPin, LOW);     // Turn off blue LED
  sendDataToThingSpeak("Red State");  // Send "Red State" to ThingSpeak

  delay(3000);  // Delay for 3 seconds

  digitalWrite(redLedPin, LOW);      // Turn off red LED
  digitalWrite(greenLedPin, HIGH);   // Turn on green LED
  digitalWrite(blueLedPin, LOW);     // Turn off blue LED
  sendDataToThingSpeak("Green State"); // Send "Green State" to ThingSpeak

  delay(3000);  // Delay for 3 seconds

  digitalWrite(redLedPin, LOW);      // Turn off red LED
  digitalWrite(greenLedPin, LOW);    // Turn off green LED
  digitalWrite(blueLedPin, HIGH);    // Turn on blue LED
  sendDataToThingSpeak("Blue State"); // Send "Blue State" to ThingSpeak

  delay(3000);  // Delay for 3 seconds
}

void sendDataToThingSpeak(String status) {
  WiFiClient client;
  if (client.connect(thingSpeakAddress, 80)) {
    String data = "field1=" + status;
    String request = "POST /update HTTP/1.1\r\n" +
                     "Host: " + String(thingSpeakAddress) + "\r\n" +
                     "Connection: close\r\n" +
                     "X-THINGSPEAKAPIKEY: " + String(writeAPIKey) + "\r\n" +
                     "Content-Type: application/x-www-form-urlencoded\r\n" +
                     "Content-Length: " + String(data.length()) + "\r\n\r\n" +
                     data;
    client.print(request); // Send the HTTP request
    delay(100);
    client.stop(); // Close the client connection
  }
}
