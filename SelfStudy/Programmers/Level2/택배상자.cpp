#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    // 택배 기사님이 미리 알려준 순서 -> order 
    int N = order.size(); 
    queue<int> q; // 컨테이너 벨트 -> queue
    stack<int> s; // 보조 컨테이너 벨트 -> stack
    
    for (int i=1; i<=N; i++) q.push(i);
    
    int idx = 0;
    while (!q.empty()) {
        if (q.front() <= order[idx]) {
            while (q.front() != order[idx]) {
                s.push(q.front());
                q.pop();
            }
            q.pop();
        }
        else { // q.front() > order[idx]
            // 보조 컨테이너 벨트를 이용해도 기사님이 원하는 순서대로 상자를 싣지 못 한다면, 더 이상 상자를 싣지 않습니다.
            if (s.empty() || s.top() != order[idx]) break;
            s.pop();
        }
        idx++;
    }
    while (!s.empty() && s.top() == order[idx]) {
        s.pop();
        idx++;
    }
    
    return idx;
}

int main() {
    vector<vector<int>> order = {
        {4,3,1,2,5},
        {5,4,3,2,1},
    };

    for (int i=0; i<order.size(); i++) {
        printf("%d\n", solution(order[i]));
    }

    return 0;
}