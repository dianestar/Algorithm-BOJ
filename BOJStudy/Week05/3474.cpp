#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    int N;
    vector<int> answers;
    for (int i=0; i<T; i++) {
        scanf("%d", &N);

        int two = 2;
        int twoCount = 0;
        int five = 5;
        int fiveCount = 0;

        while (two <= N && five <= N) {
            twoCount += N / two;
            two *= 2;
            fiveCount += N / five;
            five *= 5;
        }

        answers.push_back(twoCount < fiveCount ? twoCount : fiveCount);
    }

    for (int i=0; i<T; i++) {
        printf("%d\n", answers[i]);
    }

    return 0;
}