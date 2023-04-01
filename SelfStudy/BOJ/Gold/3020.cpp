#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDestroy = 200000;
int caseCount = 0;
vector<int> lowerObstacles;
vector<int> upperObstacles;

int main() {
	int N, H;
	scanf("%d %d", &N, &H);

	int obstacle;
	for (int i = 0; i < N; i++) {
		scanf("%d", &obstacle);

		// 석순(아래) - 종유석(위) 번갈아 등장
		if (i % 2 == 0) lowerObstacles.push_back(obstacle);
		else upperObstacles.push_back(obstacle);
	}

	// 2 <= N <= 200,000
	// 2 <= H <= 500,000
	// worst case: 200,000 * 500,000 = 100,000,000,000
	// 이분탐색 활용

	// 오름차순 정렬
	sort(lowerObstacles.begin(), lowerObstacles.end());
	sort(upperObstacles.begin(), upperObstacles.end());

	// i는 지나갈 구간 인덱스
	for (int i = 1; i <= H; i++) {
		// 아래 장애물은 길이가 i보다 크거나 같으면 파괴
		int lowerPt = lower_bound(lowerObstacles.begin(), lowerObstacles.end(), i) - lowerObstacles.begin();
		// 위 장애물은 길이가 H-i보다 크면 파괴
		int upperPt = upper_bound(upperObstacles.begin(), upperObstacles.end(), H - i) - upperObstacles.begin();

		int totalDestroy = N - (lowerPt + upperPt);

		if (totalDestroy == minDestroy) {
			caseCount++;
		}
		else if (totalDestroy < minDestroy) {
			minDestroy = totalDestroy;
			caseCount = 1;
		}
	}

	printf("%d %d", minDestroy, caseCount);

	return 0;
}