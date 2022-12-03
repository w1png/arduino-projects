#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
int sendorPin = A0;
int sensorValue;

void print_humidity(int humidity) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1, 0);
  display.print("Humidity:\n");
  display.print(humidity);
  display.print("%");
  display.display();
}

int convert_to_humidity(int sensorValue) {
  int humidity = map(sensorValue, 1023, 465, 0, 100);
  return humidity;
}

void setup() {
  // setting up the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  sensorValue = analogRead(sendorPin);
  int humidity = convert_to_humidity(sensorValue);
  print_humidity(humidity);
  delay(5000);
}

