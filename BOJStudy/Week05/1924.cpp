#include <iostream>
using namespace std;

int monthEnd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string yoil[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int daySum = 0;
    for (int i=1; i<x; i++) {
        daySum += monthEnd[i];
    }
    daySum += y;

    printf("%s", yoil[daySum % 7].c_str());

    return 0;
}