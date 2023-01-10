#include <iostream>
using namespace std;

long long X, Y, Z;
int answer = -1;	

int main() {
	scanf("%d %d", &X, &Y);

	Z = Y * 100 / X;

	// 1 <= X <= 1,000,000,000이므로 정답은 1~10억 사이에 존재함
	int start = 1;
	int end = 1000000000;
	while (start <= end) {
		int mid = (start + end) / 2;

		if ((Y + mid) * 100 / (X + mid) != Z) {
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	printf("%d", answer);

	return 0;
}