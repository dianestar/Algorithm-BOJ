#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> A;

int binary_search(int target) {
	int start = 0;
	int end = N - 1;

	bool flag = false;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (target == A[mid]) return 1;

		if (target > A[mid]) start = mid + 1;
		else end = mid - 1;
	}

	return 0;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		A.push_back(num);
	}

	// binary search를 활용하기 위해 오름차순으로 정렬
	sort(A.begin(), A.end());

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		printf("%d\n", binary_search(num));
	}

	return 0;
}