#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    deque<int> numbers;
    for (int i=0; i<N; i++) {
        numbers.push_back(i+1);
    }

    vector<int> answers;
    while (!numbers.empty()) {
        for (int i=1; i<K; i++) {
            numbers.push_back(numbers.front());
            numbers.pop_front();
        }
        answers.push_back(numbers.front());
        numbers.pop_front();
    }

    printf("<");
    for (int i=0; i<N-1; i++) {
        printf("%d, ", answers[i]);
    }
    printf("%d>", answers[N-1]);

    return 0;
}