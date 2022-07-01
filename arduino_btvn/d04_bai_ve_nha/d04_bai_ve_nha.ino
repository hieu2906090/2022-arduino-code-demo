byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

byte pinCount;

// ################################################################################
// I. CUSTOM DEV SECTION
// ################################################################################
void loopLedByMode(int soLanChay, int soTrungVi, byte mode, int delayTime) {
    for (int i = 0; i <= soLanChay; i++) {
        if (i == 0)
            digitalWrite(ledPin[soTrungVi], mode);
        else {
            digitalWrite(ledPin[soTrungVi - i], mode);
            digitalWrite(ledPin[soTrungVi + i], mode);
        }
        delay(delayTime);
    }
}

void chayLedTuTrungVi(int doDaiMang) {
    int soTrungVi = round(doDaiMang / 2);
    int soLanChay = doDaiMang - soTrungVi;
    // B1. Open led
    loopLedByMode(soLanChay, soTrungVi, HIGH, 300);
    // B2. Dim led
    loopLedByMode(soLanChay, soTrungVi, LOW, 300);
}

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
void loop() { chayLedTuTrungVi(pinCount); }
