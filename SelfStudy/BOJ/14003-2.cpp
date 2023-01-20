#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000001

int N, dSize;
int A[MAX_N];
int D[MAX_N];
int prevID[MAX_N]; // LIS에서 현재 수 바로 앞에 와야 하는 수의 인덱스 번호
int currID[MAX_N]; // 해당 캐시값의 원래 수열의 인덱스 번호
int answer[MAX_N];

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	// LIS
	D[1] = A[1];
	currID[1] = 1;
	dSize = 1;
	for (int i = 2; i <= N; i++) {
		int idx = lower_bound(D + 1, D + dSize + 1, A[i]) - D;
		D[idx] = A[i];
		currID[idx] = i;
		prevID[i] = currID[idx - 1];
		if (idx == dSize + 1) dSize++;
	}

	printf("%d\n", dSize);

	// reverse tracking
	int aIdx = currID[dSize];
	for (int i = dSize; i >= 1; i--) {
		answer[i] = A[aIdx];
		aIdx = prevID[aIdx];
	}

	for (int i = 1; i <= dSize; i++) {
		printf("%d ", answer[i]);
	}

	return 0;
}