#include <iostream>
#include <vector>
using namespace std;

int N, M, answer;
vector<vector<int>> link(101, vector<int>(101));
vector<int> visited(101);

void dfs(int computer) {
    visited[computer] = 1;
    for (int i=1; i<=N; i++) {
        if (link[computer][i] && !visited[i]) {
            answer++;
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &N);

    int a, b;
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        link[a][b] = 1;
        link[b][a] = 1;
    }

    dfs(1);

    printf("%d", answer);

    return 0;
}