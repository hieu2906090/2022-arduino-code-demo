byte ledPin[] = {2, 3, 4, 5, 6, 7, 8};

byte pinCount;

// ################################################################################
// I. CUSTOM DEV SECTION
// ################################################################################
void chayTatHayMoLED(int trungVi, int soLanLap, int highOrLow) {
    for (int i = 0; i <= soLanLap; i++) {
        if (i == 0) {
            digitalWrite(ledPin[trungVi], highOrLow);
            continue;
        }
        digitalWrite(ledPin[trungVi + i], highOrLow);
        digitalWrite(ledPin[trungVi - i], highOrLow);
        delay(500);
    }
}

void chayLedTuTrungVi() {
    int trungVi = round(pinCount / 2);
    int soLanLap = pinCount - trungVi;
    // B1. Mở LED
    // ---------------------------------------------------------------
    chayTatHayMoLED(trungVi, soLanLap, HIGH);
    delay(1000);
    // B1. Mở LED
    // ---------------------------------------------------------------
    chayTatHayMoLED(trungVi, soLanLap, LOW);
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
void loop() { chayLedTuTrungVi(); }
