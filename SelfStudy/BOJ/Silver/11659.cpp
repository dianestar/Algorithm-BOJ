#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100001

int N, M;
vector<int> numbers(MAX_N);
vector<int> sum(MAX_N);

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		scanf("%d", &numbers[n]);
		sum[n] = sum[n - 1] + numbers[n];
	}

	int i, j;
	for (int m = 1; m <= M; m++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
	}
	
	return 0;
}