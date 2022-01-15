#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int network[101][101];
int visited[101];
int N, L, count;

void bfs(int start) {
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

int main() {
    scanf("%d %d", &N, &L);

    int x, y;
    for (int i=0; i<L; i++) {
        scanf("%d %d", &x, &y);
        network[x][y] = 1;
        network[y][x] = 1;
    }

    bfs(1);

    printf("%d", count);

    return 0;
}