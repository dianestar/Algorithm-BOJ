#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 2501

int N, M, K;
vector<int> numbers;
double combination[MAX_N][MAX_N];

int main() {
	for (int i = 1; i < MAX_N; i++) {
		for (int j = 0; j <= i; j++) {
			combination[i][j] = (i == j || j == 0) ? 1 : combination[i - 1][j - 1] + combination[i - 1][j];
		}
	}

	scanf("%d", &M);
	
	int number;
	for (int i = 0; i < M; i++) {
		scanf("%d", &number);
		numbers.push_back(number);
		N += number;
	}

	scanf("%d", &K);

	double denominator = 0;
	for (int i = 0; i < M; i++) {
		if (numbers[i] >= K) denominator += combination[numbers[i]][K];
	}

	double numerator = combination[N][K];

	printf("%.9lf", denominator / numerator);

	return 0;
}