#include <iostream>
#include <vector>
using namespace std;

int N, M;
int answer = 0;
vector<int> numbers(100);

void dfs(int index, int count, int sum) {
    if (sum > M) { return; }

    if (count == 3) {
        if (sum > answer) {
            answer = sum;
        }
        return;
    }

    for (int i=index+1; i<N; i++) {
        dfs(i, count+1, sum+numbers[i]);
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i=0; i<N-2; i++) {
        dfs(i, 1, numbers[i]);
    }

    printf("%d\n", answer);

    return 0;
}