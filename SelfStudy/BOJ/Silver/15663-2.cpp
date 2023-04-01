/* dfs(재귀) 활용 풀이 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 9

int N, M;
vector<int> numbers;
vector<int> sequence(MAX_N);
vector<bool> visited(MAX_N);

void dfs(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", sequence[i]);
		}
		printf("\n");
		return;
	}

	int prev = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i] && numbers[i] != prev) {
			sequence[count] = numbers[i];
			prev = numbers[i];

			visited[i] = true;
			dfs(count + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	int number;
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		numbers.push_back(number);
	}

	sort(numbers.begin(), numbers.end());
	dfs(0);

	return 0;
}