#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> isConnected(100001);
vector<int> visited(100001, 0);
vector<int> parents(100001);

void dfs(int num) {
    visited[num] = 1;

    int len = isConnected[num].size();
    for (int i=0; i<isConnected[num].size(); i++) {
        int child = isConnected[num][i];
        if (!visited[child]) {
            parents[child] = num;
            dfs(child);
        }
    }
}

int main() {
    scanf("%d", &N);

    int a, b;
    for (int i=0; i<N-1; i++) {
        scanf("%d %d", &a, &b);
        isConnected[a].push_back(b);
        isConnected[b].push_back(a);
    }

    dfs(1);

    for (int i=2; i<=N; i++) {
        printf("%d\n", parents[i]);
    }

    return 0;
}