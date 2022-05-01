#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int x;
    priority_queue<int> pq;
    for (int i=0; i<N; i++) {
        scanf("%d", &x);
        if (x == 0 && pq.empty()) {
            printf("0\n");
        }
        else if (x == 0 && !pq.empty()) {
            printf("%d\n", pq.top());
            pq.pop();
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}