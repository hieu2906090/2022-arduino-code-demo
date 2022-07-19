#include <Servo.h>

const int trig = 8;  // chân trig của HC-SR04
const int echo = 7;  // chân echo của HC-SR04
Servo myservo;

int returnDistance() {
    unsigned long duration;  // biến đo thời gian
    int distance;            // biến lưu khoảng cách

    /* Phát xung từ chân trig */
    digitalWrite(trig, 0);  // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig, 1);  // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig, 0);  // tắt chân trig

    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo.
    duration = pulseIn(echo, HIGH);
    // Tính khoảng cách đến vật.
    distance = int(duration / 2 / 29.412);

    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.println("cm");
    delay(200);
    return distance;
}

void runServoMotor() {
    int distance;
    for (int i = 0; i < 180; i++) {
        myservo.write(i);
        delay(2);
        //        distance = returnDistance();
    }
    for (int pos = 180; pos >= 1; pos--) {
        myservo.write(pos);
        delay(2);
        //        distance = returnDistance();
    }
}

void setup() {
    myservo.attach(9);
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig, OUTPUT);  // chân trig sẽ phát tín hiệu
    pinMode(echo, INPUT);   // chân echo sẽ nhận tín hiệu
}

void loop() {
    int distance = returnDistance();
    if (distance < 10) {
        runServoMotor();
    }
}