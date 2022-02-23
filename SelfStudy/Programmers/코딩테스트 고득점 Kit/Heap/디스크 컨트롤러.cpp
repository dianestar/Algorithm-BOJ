#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    // cf) jobs의 각 행은 하나의 작업에 대한 [작업이 요청되는 시점, 작업의 소요시간]
    int answer = 0;

    // jobs를 작업 요청 시점이 빠른 순으로 정렬
    sort(jobs.begin(), jobs.end()); 
    // 작업 소요시간이 적은 순으로 저장되는 priority_queue 선언
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq; 
    int currTime = 0;
    int i = 0;
    int jobsSize = jobs.size();
    while (true) {
        if (i >= jobsSize && pq.empty()) {
            // 모든 작업 처리 완료 시 종료
            break;
        }

        while (i < jobsSize && jobs[i][0] <= currTime) {
            // 현재 시점보다 요청 시점이 빨라 소요시간 기준으로 재정렬이 필요한 작업들을 pq에 push
            pq.push({jobs[i][0], jobs[i][1]});
            i++;
        }
        if (!pq.empty()) {
            // pq가 비어있지 않을 경우
            // pq의 top에 해당하는 작업을 먼저 처리
            answer += (currTime - pq.top().first + pq.top().second);
            currTime += pq.top().second;
            pq.pop();
        }
        else {
            // pq가 비어있을 경우, 즉 현재 시점에 요청된 작업이 없을 경우
            // 다음 요청이 들어오는 시점으로 현재 시점 업데이트
            currTime = jobs[i][0];
        }
    } 
    answer /= jobsSize;

    return answer;
}

int main() {
    vector<vector<int>> jobs = {{0,3}, {1,9}, {2,6}};
    int answer = solution(jobs);
    printf("%d", answer);

    return 0;
}