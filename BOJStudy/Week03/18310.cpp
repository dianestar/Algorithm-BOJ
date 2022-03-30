#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> houseIdx(N);
    for (int i=0; i<N; i++) {
        scanf("%d", &houseIdx[i]);
    }

    sort(houseIdx.begin(), houseIdx.end());

    if (N % 2 == 1) {
        printf("%d", houseIdx[N/2]);
    }
    else {
        // cf) 단, 안테나를 설치할 수 있는 위치 값으로 여러 개의 값이 도출될 경우 가장 작은 값을 출력한다.
        printf("%d", houseIdx[N/2-1]);
    }

    return 0;
}