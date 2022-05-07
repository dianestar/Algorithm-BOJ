#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int height;
    stack<pair<int, int>> s;
    vector<int> received;
    for (int i=0; i<N; i++) {
        scanf("%d", &height);

        while (!s.empty() && s.top().second < height) {
            s.pop();
        }
        if (s.empty()) {
            received.push_back(0);
        }
        else {
            received.push_back(s.top().first);
        }

        s.push({i+1, height});
    }

    for (int i=0; i<N; i++) {
        printf("%d ", received[i]);
    }

    return 0;
}