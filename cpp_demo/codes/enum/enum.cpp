#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Trường hợp truyền có giá trị
enum dayOfWeek {
    THU_HAI = 1,
    THU_BA = 2,
    THU_TU = 3,
    THU_NAM = 4,
    THU_SAU = 5,
    THU_BAY = 6,
    CHU_NHAT = 7
};

// Trường hợp truyền không giá trị (mặc định lấy theo tăng dần từ 0 trở lên)
enum dayOfWeekEng { Mon, Tue, Wed, Thur, Fri, Sat, Sun };

int main() {
    enum dayOfWeek day = THU_HAI;
    enum dayOfWeekEng day03 = Tue;
    printf("day is %d - %d", day, day03);
    return EXIT_SUCCESS;
}