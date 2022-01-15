#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    queue<int> q;

    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        q.push(i);
    }

    int temp;
    while (q.size()!=1) {
        q.pop();
        temp=q.front();
        q.pop();
        q.push(temp);
    }

    printf("%d", q.front());

    return 0;
}
