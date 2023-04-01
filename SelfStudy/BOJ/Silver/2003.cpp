#include <iostream>
#include <vector>

using namespace std;

int N, M, answer;
vector<int> numbers;

int main() {
	scanf("%d %d", &N, &M);

	int number;
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		numbers.push_back(number);
	}

	int start = 0;
	int end = 0;
	int sum = numbers[0];
	while (1) {
		if (sum >= M) {
			if (sum == M) answer++;

			sum -= numbers[start];
			start++;
		}
		else {
			if (end == N - 1) break;

			end++;
			sum += numbers[end];
		}
	}

	printf("%d", answer);

	return 0;
}