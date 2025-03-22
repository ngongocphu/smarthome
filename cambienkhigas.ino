const int gasSensorPin = A0; // Chân analog kết nối với cảm biến gas
const int ledPin = 9;         // Chân kết nối với đèn LED
const int buzzerPin = 8;      // Chân kết nối với còi

void setup() {
  Serial.begin(9600); // Khởi động giao tiếp serial
  pinMode(ledPin, OUTPUT); // Đặt chân LED là đầu ra
  pinMode(buzzerPin, OUTPUT); // Đặt chân còi là đầu ra
}

void loop() {
  int sensorValue = analogRead(gasSensorPin); // Đọc giá trị từ cảm biến gas
  Serial.println(sensorValue); // In giá trị ra Serial Monitor

  // Kiểm tra giá trị cảm biến
  if (sensorValue > 300) { // Thay đổi ngưỡng tùy theo cảm biến
    digitalWrite(ledPin, HIGH); // Bật đèn LED
    digitalWrite(buzzerPin, HIGH); // Bật còi
  } else {
    digitalWrite(ledPin, LOW); // Tắt đèn LED
    digitalWrite(buzzerPin, LOW); // Tắt còi
  }

  delay(1000); // Đợi 1 giây trước khi kiểm tra lại
}