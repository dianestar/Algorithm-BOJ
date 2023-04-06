#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 201
#define MAX_M 1001

int N, M;
vector<vector<int>> adj(MAX_N, vector<int>(MAX_N));
vector<int> route(MAX_M);

int main() {
    // input
    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%d", &adj[i][j]);
        }
    }


    for (int i=1; i<=M; i++) {
        scanf("%d", &route[i]);
    }

    // floyd-warshall
    for (int i=1; i<=N; i++) {
        adj[i][i] = 1;
    }

    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (i == k || k == j || adj[i][j] || !adj[i][k] || !adj[k][j]) continue;
                adj[i][j] = 1;
            }
        }
    }

    // print
    bool flag = true;
    for (int i=2; i<=M; i++) {
        if (!adj[route[i-1]][route[i]]) {
            printf("NO");
            flag = false;
            break;
        }
    }

    if (flag) printf("YES");

    return 0;
}