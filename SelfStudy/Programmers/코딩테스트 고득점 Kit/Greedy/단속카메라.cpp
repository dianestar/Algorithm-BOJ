#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    // 진출 지점이 빠른 순으로 정렬
    sort(routes.begin(), routes.end(), cmp);

    int n = routes.size();

    // 가장 먼저 진출하는 차량의 진출 지점에 카메라 설치
    int camera = routes[0][1];
    int answer = 1;
    for (int i=1; i<n; i++) {
        if (routes[i][0] > camera) {
            // 진입 지점이 가장 최근에 설치된 카메라 이후일 경우
            // 해당 차량의 진출 지점에 카메라 추가 설치
            camera = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}

int main() {
    vector<vector<int>> routes = {{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}};
    int answer = solution(routes);
    printf("%d", answer);

    return 0;
}