#include <iostream>
#include <vector>

using namespace std;

int N, M, maxHeight, answer;
vector<int> heights;

long long calculateTree(int h) {
	/*
	상근이가 집에 가져갈 나무의 길이 합 구하기
	나무의 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0
	나무의 수 1 <= N <= 1,000,000 이므로
	나무의 길이 합은 int 범위를 넘어갈 수 있음
	*/
	int len = heights.size();
	long long sum = 0;
	for (int i = 0; i < len; i++) {
		if (heights[i] > h) sum += heights[i] - h;
	}
	return sum;
}

void binarySearch() {
	// binary search 활용
	int start = 0;
	int end = maxHeight;
	while (start <= end) {
		int mid = (start + end) / 2;

		long long sum = calculateTree(mid);

		if (sum >= M) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	int height;
	for (int i = 0; i < N; i++) {
		scanf("%d", &height);
		heights.push_back(height);

		// binary search의 범위를 줄이기 위해 end값으로 활용할 maxHeight 값 업데이트
		if (height > maxHeight) maxHeight = height;
	}
	
	binarySearch();
	
	printf("%d", answer);

	return 0;
}