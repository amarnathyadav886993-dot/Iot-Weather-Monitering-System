#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12,11,5,4,3,6);

void setup()
{
  lcd.begin(16,2);
  dht.begin();

  lcd.print("Weather");
  lcd.setCursor(0,1);
  lcd.print("Monitoring");
  delay(2000);
  lcd.clear();
}

void loop()
{
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C ");

  lcd.setCursor(0,1);
  lcd.print("Hum :");
  lcd.print(hum);
  lcd.print("% ");

  delay(2000);
}
