#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long completed(long long curTime, vector<int> times) {
    // curTime 시점에 심사 완료 가능한 사람 수를 return하는 함수
    long long cnt = 0;
    for (int i=0; i<times.size(); i++) {
        cnt += curTime / times[i];
    }
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end()); // 오름차순 정렬
    long long minTime = 1; // 최소 시간
    long long maxTime = times[times.size()-1] * (long long)n; // 최대 시간
    
    // 이분탐색 활용
    long long midTime;
    while (minTime <= maxTime) {
        midTime = (minTime + maxTime) / 2;
        long long cnt = completed(midTime, times);
        if (cnt >= n) {
            answer = midTime;
            maxTime = midTime - 1;
        }
        else {
            minTime = midTime + 1;
        }
    }
    
    return answer;
}

int main() {
    int n = 6;
    vector<int> times = {7, 10};

    printf("%lld", solution(n, times));

    return 0;
}