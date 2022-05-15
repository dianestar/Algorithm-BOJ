#include <iostream>
#include <vector>
using namespace  std;

int N;
int maxCount = 0;
vector<int> chosen(101);
vector<int> visited(101, 0);
vector<int> answers;

void dfs(int current, int start) {
    if (visited[current]) {
        if (current == start) {
            answers.push_back(start);
        }
    }
    else {
        visited[current] = 1;
        dfs(chosen[current], start);
    }
}

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &chosen[i]);
    }

    for (int i=1; i<=N; i++) {
        for (int j=0; j<101; j++) { visited[j] = 0; }
        dfs(i, i);
    }

    printf("%d\n", answers.size());
    for (int i=0; i<answers.size(); i++) {
        printf("%d\n", answers[i]);
    }

    return 0;
}