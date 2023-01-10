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
	// 입력받으면서 A, B 각 배열의 부 배열 합 구해놓기
	scanf("%d", &T);

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		A.push_back(num);

		subSum = 0;
		for (int j = i; j >= 0; j--) {
			subSum += A[j];
			subSumA.push_back(subSum);
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		B.push_back(num);

		subSum = 0;
		for (int j = i; j >= 0; j--) {
			subSum += B[j];
			subSumB.push_back(subSum);
		}
	}

	// 부 배열 합 오름차순 정렬
	sort(subSumA.begin(), subSumA.end());
	sort(subSumB.begin(), subSumB.end());

	int lenA = subSumA.size();
	int lenB = subSumB.size();

	// 투포인터 활용
	int start = 0; // A 부 배열 합 시작 포인터 (작은 수 부터)
	int end = lenB - 1; // B 부 배열 합 시작 포인터 (큰 수 부터)

	while (start < lenA && end >= 0) {
		int curA = subSumA[start];
		int curB = subSumB[end];
		int sum = curA + curB;

		if (sum == T) {
			long long countA = 0;
			long long countB = 0;

			while (start < lenA && subSumA[start] == curA) {
				start++;
				countA++;
			}
			while (end >= 0 && subSumB[end] == curB) {
				end--;
				countB++;
			}

			answer += countA * countB;
		}

		else if (sum < T) start++; 

		else end--;
	}

	printf("%lld", answer);

	return 0;
}