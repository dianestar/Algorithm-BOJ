#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

int N, S;
int minLen = MAX_N;
vector<int> numbers;

int main() {
	scanf("%d %d", &N, &S);

	int number;
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		numbers.push_back(number);
	}

	int start = 0;
	int end = 0;
	int sum = numbers[0];
	int len = 1;
	while (1) {
		if (sum >= S) {
			if (len < minLen) minLen = len;
			len--;
			sum -= numbers[start];
			start++;
		}
		else {
			if (end == N - 1) break;
			len++;
			end++;
			sum += numbers[end];
		}
	}

	// cf. 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.
	if (minLen == MAX_N) minLen = 0;
	printf("%d", minLen);

	return 0;
}