byte ledPin[] = {2, 3, 4, 5, 6, 7, 8};

byte pinCount;

// ################################################################################
// I. CUSTOM DEV SECTION
// ################################################################################
int chayTatHayMoLED(int highOrLow) {
    for (int i = 0; i < pinCount; i++) {
        digitalWrite(ledPin[i], highOrLow);
        delay(500);
    }
    return 1;
}

void chayLedTuTrungVi(int doDaiMang) {}

// ################################################################################
// II. MAIN RUN SECTION
// ################################################################################
void setup() {
    pinCount = sizeof(ledPin);
    for (int i = 0; i < pinCount; i++) {
        pinMode(ledPin[i], OUTPUT);
        digitalWrite(ledPin[i], LOW);
    }
}

// ---------------------------------------------------------------------------------
void loop() {
    // B1. Mở led
    chayTatHayMoLED(HIGH);
    delay(1000);
    // B2. Tắt led
    chayTatHayMoLED(LOW);
}
