/* next_permutation 활용 풀이*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define MAX_M 9

int N, M;
vector<int> numbers;
vector<int> prevSequence(MAX_M);

int main() {
	scanf("%d %d", &N, &M);

	int number;
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		numbers.push_back(number);
	}

	sort(numbers.begin(), numbers.end());

	do {
		bool isValid = true;
		vector<int> currSequence;
		for (int i = 0; i < M; i++) {
			if (i > 0 && currSequence[i - 1] > numbers[i]) {
				isValid = false;
				break;
			}
			currSequence.push_back(numbers[i]);
		}

		if (!isValid) continue;

		int count = 0;
		for (int i = 0; i < M; i++) {
			if (currSequence[i] == prevSequence[i]) count++;
		}

		if (count == M) continue;
		for (int i = 0; i < M; i++) {
			printf("%d ", currSequence[i]);
			prevSequence[i] = currSequence[i];
		}
		printf("\n");
	} while (next_permutation(numbers.begin(), numbers.end()));

	return 0;
}