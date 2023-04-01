#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 21

int N, flag;
long long factorial[MAX_N]; // 20! 까지 표현해야 하므로 long long 으로 선언
bool visited[MAX_N];

int main() {
	scanf("%d %d", &N, &flag);

	factorial[0] = 1;
	for (int i = 1; i <= 20; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	if (flag == 1) { // 1인 경우 k 입력받기
		long long k; // 20! 까지 표현해야 하므로 long long 으로 선언
		scanf("%lld", &k);
		
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[j]) {
					if (k > factorial[N - i - 1]) {
						k -= factorial[N - i - 1];
					}
					else {
						visited[j] = true;
						printf("%d ", j);
						break;
					}
				}
			}
		}
	}
	else { // 2인 경우 임의의 순열을 나타내는 N개의 수 입력받기
		vector<int> numbers;
		int number;
		for (int i = 0; i < N; i++) {
			scanf("%d", &number);
			numbers.push_back(number);
		}

		// 자릿수 왼쪽에서 오른쪽으로 visited 배열 표시하며 탐색
		// 나보다 작은 숫자로 시작하는 순열의 개수 구하기
		long long answer = 0; // 20! 까지 표현해야 하므로 long long 으로 선언
		for (int i = 0; i < N; i++) {
			visited[numbers[i]] = true;

			for (int j = 1; j < numbers[i]; j++) {
				if (!visited[j]) answer += factorial[N - i - 1];
			}
		}

		printf("%lld", answer + 1);
	}
	
	return 0;
}