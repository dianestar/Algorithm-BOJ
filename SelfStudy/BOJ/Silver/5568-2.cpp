/* dfs(재귀) 활용 풀이 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

#define MAX_N 10

int N, K;
vector<int> cards;
vector<bool> visited(MAX_N, false);
unordered_set<string> uniqueNumbers;

void dfs(string number, int count) {
	if (count == K) {
		uniqueNumbers.insert(number);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(number + to_string(cards[i]), count + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);

	int card;
	for (int i = 0; i < N; i++) {
		scanf("%d", &card);
		cards.push_back(card);
	}

	dfs("", 0);

	printf("%d", uniqueNumbers.size());

	return 0;
}