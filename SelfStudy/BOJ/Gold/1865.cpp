#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define MAX_N 501
#define MAX_VAL 

int main() {
    int TC;
    scanf("%d", &TC);

    while (TC > 0) {
        int N, M, W;
        vector<vector<int>> edges(MAX_N, vector<int>(MAX_N, INT_MAX));
        vector<int> minTime(MAX_N, 0);
        
        scanf("%d %d %d", &N, &M, &W);

        for (int i=1; i<N; i++) {
            edges[i][i] = 0;
        }

        // M개의 도로와 W개의 웜홀
        // 도로는 방향이 없으며 웜홀은 방향이 있음
        int S, E, T;
        for (int i=0; i<M; i++) {
            scanf("%d %d %d", &S, &E, &T);
            if (T < edges[S][E]) {
                edges[S][E] = T;
                edges[E][S] = T;
            }
        }    
        for (int i=0; i<W; i++) {
            scanf("%d %d %d", &S, &E, &T);
            edges[S][E] = -T;
        }

        // bellman-ford
        bool flag = false;
        for (int k=1; k<=N; k++) {
            for (int i=1; i<=N; i++) {
                for (int j=1; j<=N; j++) {
                    if (edges[i][j] == INT_MAX) continue;
                    // if (minTime[i] == INT_MAX) continue;

                    int newTime = minTime[i] + edges[i][j];
                    if (newTime < minTime[j]) {
                        if (k == N) {
                            flag = true;
                            printf("YES\n");
                            break;
                        }
                        minTime[j] = newTime;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        if (!flag) printf("NO\n");

        TC--;
    }

    return 0;
}