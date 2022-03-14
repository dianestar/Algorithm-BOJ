#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 입력
    int N;
    scanf("%d", &N);

    vector<int> v;
    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }

    // maxHeight: 오른쪽~현재 지점 중 가장 높은 막대기
    // 막대기의 높이 h의 범위 1 ≤ h ≤ 100,000 이므로 0으로 초기화
    int maxHeight = 0;
    int answer = 0; 
    for (int i=N-1; i>=0; i--) { // 맨 오른쪽부터 탐색
        if (v[i] > maxHeight) {
            answer++;
            maxHeight = v[i];
        }
    }

    // 출력
    printf("%d", answer);

    return 0;
}