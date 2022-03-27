#include <iostream>
#include <queue>
using namespace std;

#define MAX_NUM 100001

bool isOutOfRange(int number) {
    if (number < 0 || number >= MAX_NUM) {
        return true;
    }
    return false;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    queue<int> q;
    vector<int> visited(MAX_NUM, 0);
    q.push(N);
    visited[N] = 1;

    int timer = 0;
    vector<int> candidates(3, 0);
    while (!q.empty()) {
        int qSize = q.size();
        for (int i=0; i<qSize; i++) {
            int curr = q.front();
            q.pop();

            if (curr == K) {
                printf("%d", timer);
                return 0;
            }

            candidates[0] = curr-1;
            candidates[1] = curr+1;
            candidates[2] = curr*2;

            for (int j=0; j<3; j++) {
                if (isOutOfRange(candidates[j]) || visited[candidates[j]]) { continue; }
                q.push(candidates[j]);
                visited[candidates[j]] = 1;
            }
        }
        timer++;
    }

    return 0;
}