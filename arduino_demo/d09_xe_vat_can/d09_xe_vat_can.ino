#include <Servo.h>

#define IN1 6
#define IN2 5
#define IN3 4
#define IN4 3
#define MAX_SPEED 255  // từ 0-255
#define MIN_SPEED 0

const int trig = 8;  // chân trig của HC-SR04
const int echo = 7;  // chân echo của HC-SR04

Servo myservo;

// ################################################################################
// I. DISTANCE & SERVO MOTOR SECTION
// ################################################################################
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

int lookRight() {  // nhin phai lay khoang cach
    myservo.write(10);
    delay(500);
    int distance = returnDistance();
    delay(100);
    myservo.write(90);
    return distance;
}

int lookLeft() {  // nhin trai lai khoang cach
    myservo.write(170);
    delay(500);
    int distance = returnDistance();
    delay(100);
    myservo.write(90);
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

// ################################################################################
// II. DC MOTOR CODE SECTION
// ################################################################################
void motor_1_Dung() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

void motor_2_Dung() {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void motor_1_Lui(int speed) {  // speed: từ 0 - MAX_SPEED
    digitalWrite(IN1, HIGH);   // chân này không có PWM
    analogWrite(IN2, speed);
}

void motor_2_Lui(int speed) {  // speed: từ 0 - MAX_SPEED
    digitalWrite(IN3, LOW);    // chân này không có PWM
    analogWrite(IN4, speed);
}

void motor_1_Tien(int speed) {
    digitalWrite(IN1, LOW);  // chân này không có PWM
    analogWrite(IN2, speed);
}

void motor_2_Tien(int speed) {
    digitalWrite(IN3, HIGH);  // chân này không có PWM
    analogWrite(IN4, speed);
}

void turn_right() {
    motor_1_Dung();
    motor_2_Tien();
    delay(400);
}

void turn_left() {
    motor_2_Dung();
    motor_1_Tien();
    delay(400);
}

// ################################################################################
// III. MAIN SECTION
// ################################################################################
void setup() {
    //    myservo.attach(9);
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig, OUTPUT);  // chân trig sẽ phát tín hiệu
    pinMode(echo, INPUT);   // chân echo sẽ nhận tín hiệu
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    int distance_right = 0;
    int distance_left = 0;
    int distance = returnDistance();
    Serial.println(distance);
    if (distance > 15) {
        motor_1_Tien(100);
        motor_2_Tien(100);
    } else {
        motor_1_Dung();
        motor_2_Dung();
        distance_right = lookRight();
        delay(300);
        distance_left = lookLeft();
        delay(300);
        if (distance_right > distance_left && distance_right > 15) {
            turn_right();
        }
        if (distance_left > distance_right && distance_left > 15) {
            turn_left();
        }
    }
}