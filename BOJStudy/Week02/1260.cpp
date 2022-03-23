#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int N, M, V;
vector<vector<int>> edge(1001, vector<int>(1001, 0));

void dfs() {
    vector<int> visited(N+1, 0);
    stack<int> s;
    s.push(V);
    visited[V] = 1;
    printf("%d ", V);

    while (!s.empty()) {
        int curr = s.top();

        for (int i=1; i<=N; i++) {
            if (edge[curr][i] && !visited[i]) {
                s.push(i);
                visited[i] = 1;
                printf("%d ", i);
                break;
            }
            else if (i == N) {
                s.pop();
            }
        }
    }
}

void bfs() {
    vector<int> visited(N+1, 0);
    queue<int> q;
    q.push(V);
    visited[V] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        printf("%d ", curr);

        for (int i=1; i<=N; i++) {
            if (edge[curr][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);

    int a, b;
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    dfs();
    printf("\n");
    bfs();

    return 0;
}