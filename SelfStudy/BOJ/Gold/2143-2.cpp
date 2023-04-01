/* 누적합 + lower_bound/upper_bound 활용 풀ㅇ이*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, num, subSum;
long long answer = 0;
vector<int> A;
vector<int> B;
vector<int> subSumA;
vector<int> subSumB;

int main() {
	// 입력
	scanf("%d", &T);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		A.push_back(num);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		B.push_back(num);
	}

	// 누적합 구하기
	subSumA.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		subSumA.push_back(subSumA[i - 1] + A[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			subSumA.push_back(subSumA[j] - subSumA[i]);
		}
	}

	subSumB.push_back(B[0]);
	for (int i = 1; i < M; i++) {
		subSumB.push_back(subSumB[i - 1] + B[i]);
	}
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			subSumB.push_back(subSumB[j] - subSumB[i]);
		}
	}

	// 부 배열 합 오름차순 정렬
	sort(subSumA.begin(), subSumA.end());
	sort(subSumB.begin(), subSumB.end());

	int lenA = subSumA.size();

	// lower_bound / upper_bound 활용하여 카운팅
	for (int i = 0; i < lenA; i++) {
		int value = T - subSumA[i];
		long long count = upper_bound(subSumB.begin(), subSumB.end(), value) - lower_bound(subSumB.begin(), subSumB.end(), value);
		answer += count;
	}

	printf("%lld", answer);

	return 0;
}