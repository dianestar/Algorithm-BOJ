#include <iostream>
// #include <stack>
// #include <queue>
using namespace std;

// stack<int> s;
// queue<int> q;
int network[101][101];
int visited[101];
int N, L, count;

void dfs_recursion(int curr) {
    visited[curr] = 1;
    for (int i=1; i<=N; i++) {
        if (network[curr][i] && !visited[i]) {
            count++;
            dfs_recursion(i);
        }
    }
}

/*
void dfs_stack(int start) {
    visited[start] = 1;
    s.push(start);
    while (!s.empty()) {
        int curr = s.top();
        int i;
        for (i=1; i<=N; i++) {
            if (network[curr][i] && !visited[i]) {
                count++;
                visited[i] = 1;
                s.push(i);
                break;
            }
        }
        if (i == N+1) {
            s.pop();
        }
    }
}

void bfs_queue(int start) {
    visited[start] = 1;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i=1; i<=N; i++) {
            if (network[curr][i] && !visited[i]) {
                count++;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
*/

int main() {
    scanf("%d %d", &N, &L);

    int x, y;
    for (int i=0; i<L; i++) {
        scanf("%d %d", &x, &y);
        network[x][y] = 1;
        network[y][x] = 1;
    }

    dfs_recursion(1);
    // dfs_stack(1);
    // bfs_queue(1);

    printf("%d", count);

    return 0;
}