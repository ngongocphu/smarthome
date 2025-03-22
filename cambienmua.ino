const int fireSensorPin = A0; // Chân analog kết nối với cảm biến
const int buzzerPin = 8;      // Chân digital kết nối với còi
int sensorValue = 0;          // Biến lưu giá trị cảm biến
const int threshold = 300;    // Ngưỡng phát hiện lửa (có thể điều chỉnh)

void setup() {
  Serial.begin(9600);           // Khởi động giao tiếp Serial
  pinMode(buzzerPin, OUTPUT);   // Đặt chân còi là đầu ra
}

void loop() {
  sensorValue = analogRead(fireSensorPin); // Đọc giá trị từ cảm biến
  Serial.println(sensorValue); // In giá trị ra Serial Monitor

  // Kiểm tra nếu phát hiện lửa
  if (sensorValue > threshold) {
    Serial.println("Lửa phát hiện!");
    digitalWrite(buzzerPin, HIGH); // Bật còi
  } else {
    digitalWrite(buzzerPin, LOW); // Tắt còi
  }

  delay(1000); // Đợi 1 giây trước khi đọc lại
}