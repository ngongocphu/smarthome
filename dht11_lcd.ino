#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2         // Chân kết nối với DHT11
#define DHTTYPE DHT11    // Chọn loại cảm biến DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Địa chỉ I2C của LCD

void setup() {
  lcd.begin();              // Khởi động LCD
  dht.begin();              // Khởi động DHT11
  lcd.print("Nhiet Do:");   // Hiển thị tiêu đề
}

void loop() {
  float h = dht.readHumidity();    // Đọc độ ẩm
  float t = dht.readTemperature(); // Đọc nhiệt độ

  // Kiểm tra xem có lỗi trong việc đọc dữ liệu không
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 1);
    lcd.print("Loi Doc Du Lieu");
    return;
  }

  // Hiển thị nhiệt độ và độ ẩm lên LCD
  lcd.setCursor(0, 1);
  lcd.print("Nhiet Do: ");
  lcd.print(t);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Do Am: ");
  lcd.print(h);
  lcd.print(" %");

  delay(2000); // Đợi 2 giây trước khi đọc lại
}