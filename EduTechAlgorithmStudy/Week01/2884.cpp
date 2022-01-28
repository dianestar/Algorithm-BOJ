#include <stdio.h>

int main() {
	int H, M;
	scanf("%d %d", &H, &M);

	if (H == 0 && M < 45) { H = 24;	}
	int t;
	t = H * 60 + M;
	t -= 45;

	printf("%d %d", t / 60, t % 60);

	return 0;
}