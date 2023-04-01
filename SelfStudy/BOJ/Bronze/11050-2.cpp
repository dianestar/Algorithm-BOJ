/* combination 재귀 활용 풀이 */

#include <iostream>
using namespace std;

#define MAX_N 11

int N, K;

int combination(int n, int k) {
	// 파스칼의 삼각형 nCk = n-1Ck-1 + n-1Ck
	if (n == k || k == 0) return 1;
	return combination(n - 1, k - 1) + combination(n - 1, k);
}

int main() {
	scanf("%d %d", &N, &K);
	printf("%d", combination(N, K));
	
	return 0;
}