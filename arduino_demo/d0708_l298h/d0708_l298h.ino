#include <NewPing.h>
#include <Servo.h>

#define IN1 6
#define IN2 5
#define IN3 4
#define IN4 3
#define MAX_SPEED 255  // từ 0-255
#define MIN_SPEED 0
#define MAX_DISTANCE 200

int distance = 100;

const int trig = 8;  // chân trig của HC-SR04
const int echo = 7;  // chân echo của HC-SR04

Servo servo_motor;

NewPing sonar(trig, echo, MAX_DISTANCE);

// ################################################################################
// I. DISTANCE & SERVO MOTOR SECTION
// ################################################################################
int read_ping() {
    delay(70);
    int cm = sonar.ping_cm();
    if (cm == 0) {
        cm = 250;
    }
    return cm;
}
int look_right() {  // nhin phai lay khoang cach
    servo_motor.write(10);
    delay(500);
    int distance = read_ping();
    delay(100);
    servo_motor.write(90);
    return distance;
}

int look_left() {  // nhin trai lai khoang cach
    servo_motor.write(170);
    delay(500);
    int distance = read_ping();
    delay(100);
    servo_motor.write(90);
    return distance;
    delay(100);
}
// ################################################################################
// II. DC MOTOR CODE SECTION
// ################################################################################
void di_thang() {
    digitalWrite(IN1, HIGH);
    analogWrite(IN2, 200);
    digitalWrite(IN4, LOW);
    analogWrite(IN3, 200);
}

void dung_lai() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void lui() {
    digitalWrite(IN1, LOW);
    analogWrite(IN2, 200);
    digitalWrite(IN3, HIGH);
    analogWrite(IN4, 200);
}

void re_phai() {
    digitalWrite(IN1, HIGH);
    analogWrite(IN2, 200);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void re_trai() {
    digitalWrite(IN3, HIGH);
    analogWrite(IN4, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

// ################################################################################
// III. MAIN SECTION
// ################################################################################
void setup() {
    myservo.attach(9);
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig, OUTPUT);  // chân trig sẽ phát tín hiệu
    pinMode(echo, INPUT);   // chân echo sẽ nhận tín hiệu
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    int distanceRight = 0;
    int distanceLeft = 0;
    delay(50);

    if (distance <= 20) {
        dung_lai();  // dung lai
        delay(300);
        lui();  // lui ve sau
        delay(400);
        dung_lai();  // dung lai
        delay(300);
        distanceRight = look_right();  // lay khoang cach ben trai
        delay(300);
        distanceLeft = look_left();  // lay khoang cach ben phai
        delay(300);
        if (distance >= distanceLeft) {
            // neu khoang cach toi da >= khoang cach ben trai thi re phai
            re_phai();
            dung_lai();
        } else {
            // ko thi re trai
            re_trai();
            dung_lai();
        }
    } else {
        di_thang();  // ko phai 2 truong hop tren thi chay thang
    }
    distance = read_ping();
}