ABSTRACT:
The plant monitoring system described in this project can be controlled remotely via the Blynk app. The main features include a PIR sensor for movement detection, an optional soil moisture sensor for possible irrigation control, and a DHT11 temperature sensor for monitoring the plant's surroundings. The LCD shield displays the sensor data locally, and they are wirelessly relayed to the Blynk app so that temperature, soil moisture, and movement detection events may be monitored remotely. Users may access real-time data and gain insights into their plant's environment with the Blynk app, and the PIR sensor can provide useful information about potential disturbances close to the plant. Plant enthusiasts now have a handy way to remotely check on the health of their plants and make educated decisions thanks to this portable gadget. Regarding possible treatments based on movement sensing, irrigation, and maintenance. Subsequent versions can include a light sensor for more thorough environmental monitoring or investigate other sensors for particular plant requirements. 

MATERIALS REQUIRED:

Hardware Requirements:
Arduino Uno:A microcontroller board that will collect sensor data and send it to the ESP32 via serial communication.
ESP32 Board: A Wi-Fi enabled microcontroller board that will connect to your WiFi network and send sensor data to the Blynk app. Choose a specific ESP32 board based on your project needs and available options (e.g., ESP32 Dev Module, ESP32 Dev Kit C).
DHT Sensor (DHT11 or DHT22): Measures temperature and humidity. Choose the appropriate sensor based on its operating temperature range and desired accuracy.
Soil Moisture Sensor: Detects the moisture level in the soil. Analog sensors are commonly used.
PIR Sensor : Detects movement in the vicinity of the plant (optional).
Relay Module: Controls the water pump based on soil moisture readings. Choose a relay module with a voltage and current rating suitable for your water pump.
Water Pump : Provides water to the plant when activated by the relay module (optional). Choose a pump based on the water pressure and flow rate required for your plants.
Breadboard: Used for prototyping and connecting various components.
Jumper Wires: Used for connecting components on the breadboard.
LCD Display : Displays sensor data locally (optional). Choose an LCD with an I2C interface for easier connection.
Power Supply:Provides power to the Arduino Uno and ESP32 board. A USB cable connected to your computer or a dedicated power supply can be used.

 Software Requirements:

Arduino IDE:Integrated Development Environment (IDE) used to write and upload code to the Arduino Uno and ESP32 boards. * **Blynk App:** Mobile application for creating a user interface to visualize sensor data. Download it from the App Store or Google Play Store.
Blynk Library:Library for Arduino that enables communication with the Blynk app. Install it through the Arduino Library Manager.
DHT Library: Library for Arduino that simplifies communication with DHT sensors. Install it through the Arduino Library Manager (if needed based on your DHT sensor type).
LiquidCrystal_I2C Library : Library for Arduino that simplifies communication with I2C LCD displays. Install it through the Arduino Library Manager (if using an I2C LCD).

WORKING OF THE PROJECT:
1. Sensor Data Acquisition (Arduino Uno):

- The Arduino Uno is connected to various sensors:
 -DHT sensor (DHT11 or DHT22) for measuring temperature and humidity.
 - Soil moisture sensor for detecting the moisture level in the soil.
 -PIR sensor (optional) for detecting movement near the plant.
-The Arduino reads sensor data periodically and processes it.

2. Data Transmission to ESP32 (Serial Communication):

-The Arduino transmits the collected sensor data (temperature, humidity, soil moisture, and PIR detection status - optional) to the ESP32 board over serial communication.
-The data is sent in a format recognizable by the ESP32 code (e.g., comma-separated values).

3. WiFi Connection and Blynk Communication (ESP32):

-The ESP32 board connects to your WiFi network using the credentials defined in the code.
-The ESP32 code utilizes the Blynk library to establish communication with the Blynk app.
-The ESP32 receives sensor data from the Arduino Uno via serial communication.

4. Data Visualization on Blynk App:

-The ESP32 transmits the received sensor data (temperature, humidity, soil moisture, and PIR detection status - optional) to the Blynk app.
- You will have created a Blynk project with a template that defines how the data should be displayed on the app.
- The Blynk app receives the data from the ESP32 and displays it on widgets like gauges, graphs, or text labels based on the template configuration.

5.  Automated Watering System:

-The Arduino code can be extended to control a water pump using a relay module.
-Based on the soil moisture readings, the Arduino can activate the relay, turning on the water pump to deliver water to the plant.
-This automation helps maintain optimal moisture levels in the soil.

