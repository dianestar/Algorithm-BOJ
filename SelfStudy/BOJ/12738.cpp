#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000001

int N;
vector<int> A(MAX_N);
vector<int> D(MAX_N, 1);

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	// LIS
	D[1] = A[1];
	int idx = 1;
	for (int i = 2; i <= N; i++) {
		// 넣으려는 수보다 작지 않은 최초의 수의 자리에 넣기
		// 작지 않은 수가 없다면 (넣으려는 수가 가장 크다면) 마지막 위치에 넣기
		if (A[i] > D[idx]) D[++idx] = A[i];
		else {
			// 배열 D의 사이즈가 커지게 되면 앞에서부터 비교하는 게 부담이 커짐
			// 배열 D는 필연적으로 오름차순이므로 이진탐색 활용
			int lowerIdx = lower_bound(D.begin() + 1, D.begin() + idx, A[i]) - D.begin();
			D[lowerIdx] = A[i];
		}
	}

	printf("%d", idx);

	return 0;
}