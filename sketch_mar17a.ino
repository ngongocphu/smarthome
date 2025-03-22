const int rainSensorPin = A0; // Chân kết nối với cảm biến mưa
int rainValue = 0; // Biến lưu giá trị đọc được

void setup() {
  Serial.begin(9600); // Khởi động Serial monitor
}

void loop() {
  rainValue = analogRead(rainSensorPin); // Đọc giá trị từ cảm biến
  Serial.print("Giá trị cảm biến mưa: ");
  Serial.println(rainValue); // In giá trị ra Serial monitor

  // Kiểm tra giá trị cảm biến
  if (rainValue < 500) { // Ngưỡng có thể điều chỉnh
    Serial.println("Có mưa!");
  } else {
    Serial.println("Không có mưa!");
  }

  delay(1000); // Đợi 1 giây trước khi đọc lại
}