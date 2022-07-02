dsPin = [2, 3, 4, 5, 6, 7, 8]


def chayTatHayMoLED(trungVi, soLanLap, highOrLow):
    for i in range(0, soLanLap + 1):
        if (i == 0):
            print(dsPin[trungVi], highOrLow)
            continue
        print(dsPin[trungVi] + i, highOrLow, end=' ')
        print(dsPin[trungVi] - i, highOrLow)


chayTatHayMoLED(4, 3, 'HIGH')
