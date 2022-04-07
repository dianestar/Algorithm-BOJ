#include <iostream>
#include <queue>
using namespace std;

struct Signal {
    int D;
    int R;
    int G;
};

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    queue<Signal> q;
    int D, R, G;
    for (int i=0; i<N; i++) {
        scanf("%d %d %d", &D, &R, &G);
        q.push({D, R, G});
    }

    int timestamp = q.front().D;
    int position = q.front().D;
    while (!q.empty()) {
        Signal curr = q.front();
        q.pop();

        int timeLeft = timestamp % (curr.R + curr.G);
        if (timeLeft <= curr.R) {
            timestamp += (curr.R - timeLeft);    
        }
        Signal next = q.front();
        timestamp += next.D - position;
        position = next.D;
    }

    timestamp += L - position;

    printf("%d", timestamp);

    return 0;
}