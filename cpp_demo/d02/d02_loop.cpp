#include <iostream>
using namespace std;

int main() {
    int testArr[] = {10, 11, 22, 55, 1000};
    int arraySize = sizeof(testArr) / sizeof(int);
    for (int i = 0; i < arraySize; i++) {
        cout << testArr[i] << "\n";
    }
    return 0;
}