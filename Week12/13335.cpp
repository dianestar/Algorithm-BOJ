#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, w, L;
    scanf("%d %d %d", &n, &w, &L);

    queue<int> trucks;
    int num;
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        trucks.push(num);
    }

    queue<int> bridge;
    int currWeight = 0;
    int currTime = 0;

    while (!trucks.empty()) {
        if (bridge.size() == w) {
            currWeight -= bridge.front();
            bridge.pop();
        }

        if (currWeight + trucks.front() <= L) {
            currWeight += trucks.front();
            bridge.push(trucks.front());
            trucks.pop();
            currTime++;
        }
        
        else {
            bridge.push(0);
            currTime++;
        }
    }

    if (bridge.size() != w) {
        while (bridge.size() < w) {
            bridge.push(-1);
            currTime++;
        }
    }

    while (!bridge.empty() && bridge.front() != -1) {
        bridge.pop();
        currTime++;
    }

    printf("%d", currTime);

    return 0;
}