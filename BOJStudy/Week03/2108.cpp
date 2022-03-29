#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

int main() {
    int N;
    scanf("%d", &N);

    int number;
    int sum = 0;
    vector<int> numbers;
    unordered_map<int, int> frequency;
    for (int i=0; i<N; i++) {
        scanf("%d", &number);
        numbers.push_back(number);
        sum += number;
        frequency[number]++;
    }

    sort(numbers.begin(), numbers.end());

    // 산술평균
    printf("%d\n", (int)(floor(sum / (float)N + 0.5)));

    // 중앙값
    printf("%d\n", numbers[N/2]);

    // 최빈값
    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> maxHeap;
    for (auto iter=frequency.begin(); iter != frequency.end(); iter++) {
        maxHeap.push({iter->first, iter->second});
    }
    pair<int, int> mostFrequent = maxHeap.top();
    maxHeap.pop();
    if (mostFrequent.second == maxHeap.top().second) {
        printf("%d\n", maxHeap.top().first);
    }
    else {
        printf("%d\n", mostFrequent.first);
    }

    // 범위
    printf("%d\n", numbers[N-1]-numbers[0]); 

    return 0;
}