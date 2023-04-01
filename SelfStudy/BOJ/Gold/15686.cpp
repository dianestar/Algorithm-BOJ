#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_INT 2147483647

int N, M, chickenCount, houseCount;
int answer = MAX_INT;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<bool> selected;

void calculateDist() {
	int totalDist = 0;

	for (int i = 0; i < houseCount; i++) {
		int minDist = MAX_INT;

		for (int j = 0; j < chickenCount; j++) {
			if (selected[j]) {
				int dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
				minDist = min(minDist, dist);
			}
		}

		totalDist += minDist;
	}

	answer = min(answer, totalDist);
}

void selectChicken(int idx, int count) {
	if (count == M) {
		calculateDist();
		return;
	}

	if (idx >= chickenCount) return;

	selected[idx] = true;
	selectChicken(idx + 1, count + 1);
	selected[idx] = false;

	selectChicken(idx + 1, count);
}

void input() {
	scanf("%d %d", &N, &M);

	int flag;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &flag);
			if (flag == 1) {
				house.push_back({ i, j });
				houseCount++;
			}
			else if (flag == 2) {
				chicken.push_back({ i, j });
				chickenCount++;
			}
		}
	}

	for (int i = 0; i < chickenCount; i++) selected.push_back(false);
}

void print() {
	printf("%d", answer);
}

int main() {
	input();
	selectChicken(0, 0);
	print();

	return 0;
}