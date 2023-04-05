#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 501

int N;
vector<int> time(MAX_N);
vector<int> answer(MAX_N);
vector<int> indegree(MAX_N);
vector<vector<int>> adj(MAX_N, vector<int>(MAX_N));

int main() {
    scanf("%d", &N);

    int pre;
    for (int i=1; i<=N; i++) {
        scanf("%d", &time[i]);

        while (1) {
            scanf("%d", &pre);
            if (pre == -1) break;
            indegree[i]++;
            adj[pre][i] = 1;
        }
    }    

    queue<int> q;
    for (int i=1; i<=N; i++) {
        if (!indegree[i]) {
            q.push(i);
            answer[i] = time[i];
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i=1; i<=N; i++) {
            if (adj[curr][i]) {
                indegree[i]--;
                if (!indegree[i]) q.push(i);                
                answer[i] = max(answer[i], time[i] + answer[curr]);
            }
        }
    }

    for (int i=1; i<=N; i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}