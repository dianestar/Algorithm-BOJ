#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, num;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        if (i%2 == 0) {
            maxheap.push(num);
        }
        else {
            minheap.push(num);
        }
        if (maxheap.empty() == 0 && minheap.empty() == 0 && maxheap.top() > minheap.top()) {
            int maxtop = maxheap.top();
            int mintop = minheap.top();
            maxheap.pop();
            maxheap.push(mintop);
            minheap.pop();
            minheap.push(maxtop);
        }
        printf("%d\n", maxheap.top());
    }

    return 0;
}