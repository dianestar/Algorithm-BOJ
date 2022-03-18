#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> isBad(200, vector<int>(200, 0));
vector<int> selected;

int main() {
    scanf("%d %d", &N, &M);

    int a, b;
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        isBad[a][b] = 1;
        isBad[b][a] = 1;
    }

    int answer = N * (N-1) * (N-2) / 6;
    for (int i=0; i<N-3; i++) { selected.push_back(0); }
    for (int i=0; i<3; i++) { selected.push_back(1); }
    do {
        vector<int> combi;
        for (int i=0; i<N; i++) {
            if (selected[i]) {
                combi.push_back(i);
            }
        }
        if (isBad[combi[0]][combi[1]] || isBad[combi[1]][combi[2]] || isBad[combi[2]][combi[0]]) {
            answer--;
        }
    } while (next_permutation(selected.begin(), selected.end()));

    printf("%d", answer);

    return 0;
}