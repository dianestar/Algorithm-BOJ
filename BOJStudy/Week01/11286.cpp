#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    int N;
    scanf("%d", &N);

    priority_queue<int, vector<int>, Cmp> pq;
    vector<int> answer;

    int x;
    for (int i=0; i<N; i++) {
        scanf("%d", &x);

        if (x != 0) { pq.push(x); }
        else {
            if (pq.empty()) { answer.push_back(0); }
            else {
                answer.push_back(pq.top());
                pq.pop();
            }
        }
    }

    for (int i=0; i<answer.size(); i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}