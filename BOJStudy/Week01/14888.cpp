#include <iostream>
#include <vector>
using namespace std;

int minValue = 2147483647;
int maxValue = -2147483647;
int N;
vector<int> numbers;
vector<int> operators(4);

void calculate(int index, int value) {
    if (index == N) {
        if (value < minValue) { minValue = value; }
        if (value > maxValue) { maxValue = value; }
        return;
    }

    if (operators[0]) {
        operators[0]--;
        calculate(index+1, value+numbers[index]);
        operators[0]++;
    }
    if (operators[1]) {
        operators[1]--;
        calculate(index+1, value-numbers[index]);
        operators[1]++;
    }
    if (operators[2]) {
        operators[2]--;
        calculate(index+1, value*numbers[index]);
        operators[2]++;
    }
    if (operators[3]) {
        operators[3]--;
        calculate(index+1, value/numbers[index]);
        operators[3]++;
    }
}

int main() {
    scanf("%d", &N);

    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        numbers.push_back(num);
    }

    for (int i=0; i<4; i++) {
        scanf("%d", &operators[i]);
    }

    calculate(1, numbers[0]);

    printf("%d\n%d", maxValue, minValue);

    return 0;
}