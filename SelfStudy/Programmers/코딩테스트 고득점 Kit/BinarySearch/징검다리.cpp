#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end()); // 오름차순 정렬
    int start = 0;
    int end = distance;
    
    while (start <= end) {
        int mid = (start + end) / 2; // 목표로 잡은 거리의 최솟값
        
        // 상정한 목표 최솟값(mid)보다 짧은 거리가 가능할 경우 바위 제거
        int adj = 0;
        int cnt = 0;
        int size = rocks.size();
        for (int i=0; i<size; i++) {
            // 출발지점~바위 또는 바위~바위 간 거리 체크
            if (rocks[i] - adj < mid) { // 바위 제거 O
                cnt++;
            }
            else { // 바위 제거 X
                adj = rocks[i]; // 인접한 바위를 현재 바위로 업데이트
            }
        }
        // 마지막 바위~도착지점 간 거리 체크
        if (distance - adj < mid) {
            cnt++;
        }
        
        if (cnt <= n) { // 거리의 최솟값을 mid로 맞출 수 있는 경우
            // cf) 바위를 n개 제거한 뒤 각 지점 사이의 거리의 최솟값 중에 가장 큰 값을 return
            if (mid > answer) {
                answer = mid;
            }
            start = mid + 1;
        }
        else { // 거리의 최솟값을 mid로 맞출 수 없는 경우 
            end = mid - 1;
        }
    }
    
    return answer;
}

int main() {
    int distance = 25;
    vector<int> rocks = {2, 14, 11, 21, 17};
    int n = 2;
    
    printf("%d", solution(distance, rocks, n));

    return 0;
}