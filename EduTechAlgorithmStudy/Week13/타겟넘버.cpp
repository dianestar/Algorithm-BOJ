#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer;

void search(vector<int> numbers, int i, int sum, int target) {
    if (i == numbers.size()) {
        if (sum == target) { answer++; }
    }
    else {
        search(numbers, i+1, sum+numbers[i], target);
        search(numbers, i+1, sum-numbers[i], target);
    }
}

int solution(vector<int> numbers, int target) {
    int sum = 0;
    search(numbers, 0, sum, target);
    return answer;
}

int main() {
    vector<int> numbers;
    for (int i=0; i<5; i++) {
        numbers.push_back(1);
    }
    int target = 3;

    printf("%d", solution(numbers, target));

    return 0;
}