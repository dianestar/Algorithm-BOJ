#include <stdio.h>

int main() {
	int year;

	scanf("%d", &year);
	printf("%d", year % 4 == 0 && year % 100 || year % 400 == 0);

	return 0;
}