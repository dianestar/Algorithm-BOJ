#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int N = people.size();
    
    // vector를 deque로 변환
    deque<int> dq;
    for (int i=0; i<N; i++) {
        dq.push_back(people[i]);
    }

    // 내림차순 정렬
    sort(dq.begin(), dq.end(), greater<int>());
    
    // cf) 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.
    while (!dq.empty()) {
        int heavier = dq.front(); 
        dq.pop_front();
        if (!dq.empty() && dq.back() <= limit - heavier) {
            dq.pop_back();
        }
        answer++;
    }

    return answer;
}

int main() {
    vector<vector<int>> people = {{70,50,80,50}, {70,80,50}};
    vector<int> limit = {100, 100};

    for (int i=0; i<people.size(); i++) {
        printf("%d\n", solution(people[i], limit[i]));
    }

    return 0;
}