
#include <dht.h>
#include <LiquidCrystal.h>

// Initialize DHT sensor
dht DHT;
#define DHT11_PIN 7

// Initialize LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Wait for components to stabilize
  delay(100);

  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Clear the display
  lcd.clear();

  // Display a welcome message
  lcd.print("Temp & Humidity");
  lcd.setCursor(0, 1);
  lcd.print("Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read data from DHT11
  int chk = DHT.read11(DHT11_PIN);

  // Check if reading was successful
  if (chk == DHTLIB_OK) {
    // Convert Celsius to Fahrenheit
    float fahrenheit = (DHT.temperature * 9.0 / 5.0) + 32.0;

    // Display temperature in Celsius on the first line
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(DHT.temperature);
    lcd.print((char)223); // Degree symbol
    lcd.print("C ");

    // Display temperature in Fahrenheit
    lcd.print(fahrenheit);
    lcd.print((char)223); // Degree symbol
    lcd.print("F");

    // Display humidity on the second line
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
  } else {
    // If reading failed, display an error message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.setCursor(0, 1);
    lcd.print("Check wiring");
  }

  // Wait 2 seconds before next reading
  delay(2000);
}
