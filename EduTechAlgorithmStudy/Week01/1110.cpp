#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int nCopy = N;
	int left, right, sum, newNum=-1;
	int cycle = 0;
	while (newNum!=nCopy) {
		left = N / 10;
		right = N % 10;
		sum = left + right;
		newNum = right * 10 + sum % 10;
		N = newNum;
		cycle++;
	}

	printf("%d", cycle);

	return 0;
}