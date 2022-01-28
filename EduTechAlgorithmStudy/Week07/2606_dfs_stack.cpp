#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int network[101][101];
int visited[101];
int N, L, count;

void dfs(int start) {
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

int main() {
    scanf("%d %d", &N, &L);

    int x, y;
    for (int i=0; i<L; i++) {
        scanf("%d %d", &x, &y);
        network[x][y] = 1;
        network[y][x] = 1;
    }

    dfs(1);

    printf("%d", count);

    return 0;
}