#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000001

int N, idx;
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
	idx = 1;
	for (int i = 2; i <= N; i++) {
		if (A[i] > D[idx]) {
			D[++idx] = A[i];
			currID[idx] = i;
			prevID[i] = currID[idx - 1];
		}
		else {
			int lowerIdx = lower_bound(D + 1, D + idx, A[i]) - D;
			D[lowerIdx] = A[i];
			currID[lowerIdx] = i;
			prevID[i] = currID[lowerIdx - 1];
		}
	}

	printf("%d\n", idx);

	// reverse tracking
	int aIdx = currID[idx];
	for (int i = idx; i >= 1; i--) {
		answer[i] = A[aIdx];
		aIdx = prevID[aIdx];
	}

	for (int i = 1; i <= idx; i++) {
		printf("%d ", answer[i]);
	}

	return 0;
}