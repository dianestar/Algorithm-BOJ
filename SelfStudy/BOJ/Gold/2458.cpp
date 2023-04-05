#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX_N 501

int N, M, answer;
vector<vector<int>> adj(MAX_N, vector<int>(MAX_N, INT_MAX));

int main() {
    scanf("%d %d", &N, &M);

    int a, b;
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
    }

    // floyd-warshall
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (adj[i][k] == INT_MAX || adj[k][j] == INT_MAX) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // i번 학생보다 작거나 i번 학생보다 큰 학생들의 수의 합이 N-1일 경우 i번 학생은 자신의 키가 몇 번째인지 알 수 있음
    for (int i=1; i<=N; i++) {
        int count = 0;
        for (int j=1; j<=N; j++) {
            if (adj[i][j] != INT_MAX || adj[j][i] != INT_MAX) count++;
        }
        if (count == N-1) answer++;
    }

    printf("%d", answer);

    return 0;
}