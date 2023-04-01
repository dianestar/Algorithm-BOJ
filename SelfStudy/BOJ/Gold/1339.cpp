#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_ALPHABET 10
#define MAX_STRLEN 8

int N, answer;
vector<int> alphabet(26);

int main() {	
	scanf("%d", &N);

	char str[MAX_STRLEN];
	for (int i = 0; i < N; i++) {
		scanf("%s", str);

		int len = strlen(str);
		for (int j = 0; j < len; j++) {
			alphabet[str[j] - 'A'] += pow(10, len - 1 - j);
		}
	}

	sort(alphabet.begin(), alphabet.end(), greater<int>());

	for (int i = 0; i < MAX_ALPHABET; i++) {
		if (alphabet[i] == 0) break;
		answer += alphabet[i] * (9 - i);
	}

	printf("%d", answer);

	return 0;
}