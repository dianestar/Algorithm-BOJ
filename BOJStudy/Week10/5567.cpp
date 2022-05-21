#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);

    int a, b;
    vector<vector<int>> isFriend(N+1, vector<int>(N+1, 0));
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        isFriend[a][b] = 1;
        isFriend[b][a] = 1;
    }

    vector<int> visited(N+1, 0);
    queue<int> q;
    int answer = 0;
    for (int i=2; i<=N; i++) {
        if (isFriend[1][i]) {
            visited[i] = 1;
            q.push(i);
            answer++;
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i=2; i<=N; i++) {
            if (isFriend[curr][i] && !visited[i]) {
                visited[i] = 1;
                answer++;
            }
        }
    }

    printf("%d", answer);

    return 0;
}