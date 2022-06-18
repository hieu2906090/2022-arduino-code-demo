int led = 13;

void setup() {
  Serial.begin(9600); // Mở cổng Serial ở mức 9600
  // Khai báo các chân INPUT OUTPUT của chương trình
  pinMode(A0, INPUT);
  pinMode (13, OUTPUT);
}
 
void loop() {
  int value = analogRead(A0); // Đọc giá trị do cảm biến độ ẩm đọc vào và gán vào biến value
  Serial.println(value);
  delay(10);

  // Nếu giá trị độ ẩm <= 800 thì ra lệnh mở đèn LED
  if (value <= 800) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
