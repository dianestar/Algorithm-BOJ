/* next_permutation 활용 풀이 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int N, K;
vector<int> cards;
unordered_set<string> uniqueNumbers;

int main() {
	scanf("%d %d", &N, &K);

	int card;
	for (int i = 0; i < N; i++) {
		scanf("%d", &card);
		cards.push_back(card);
	}

	// next_permutation을 활용하기 위해 오름차순 정렬
	sort(cards.begin(), cards.end());

	// worst case: 10! == 3628800
	do {
		string number = "";
		for (int i = 0; i < K; i++) {
			number += to_string(cards[i]);
		}
		uniqueNumbers.insert(number);
	} while (next_permutation(cards.begin(), cards.end()));

	printf("%d", uniqueNumbers.size());

	return 0;
}