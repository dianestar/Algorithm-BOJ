#include <iostream>
#include <vector>
using namespace std;

int N;
int maxResult = -1000000001;
int minResult = 100000001;
vector<int> nums;
int ops[4]; //ops[0]:+ ops[1]:- ops[2]:* ops[3]: 4

void calculate(int i, int result) {
    if (i == N-1) {
        if (result > maxResult) { maxResult = result; }
        if (result < minResult) { minResult = result;}
        return;
    }

    else {
        if (ops[0] > 0) { // addition
            ops[0]--;
            calculate(i+1, result+nums[i+1]);
            ops[0]++;
        }
        if (ops[1] > 0) { // substraction
            ops[1]--;
            calculate(i+1, result-nums[i+1]);
            ops[1]++;
        }
        if (ops[2] > 0) { //multiplication
            ops[2]--;
            calculate(i+1, result*nums[i+1]);
            ops[2]++;
        }
        if (ops[3] > 0) { //division
            ops[3]--;
            calculate(i+1, result/nums[i+1]);
            ops[3]++;
        }
    }
}

int main() {
    scanf("%d", &N);

    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        nums.push_back(num);
    }

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    ops[0] = a;
    ops[1] = b;
    ops[2] = c;
    ops[3] = d;

    calculate(0, nums[0]);
    printf("%d\n%d\n", maxResult, minResult);

    return 0;
}