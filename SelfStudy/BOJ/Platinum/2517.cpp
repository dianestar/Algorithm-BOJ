#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 500000
#define TREE_SIZE (1024 * 512 * 2)

int N, nn;
vector<pair<int, int>> skills;
vector<int> tree(TREE_SIZE, 0);
vector<int> answers(MAX_N);

void init() {
	for (nn = 1; nn < N; nn *= 2);
}

void update(int idx, int val) {
	idx += nn;
	tree[idx] = val;

	while (idx) {
		idx /= 2;
		tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
	}
}

int query(int left, int right) {
	left += nn;
	right += nn;
	int ret = 0;

	while (left <= right) {
		if (left % 2 == 1) ret += tree[left++];
		if (right % 2 == 0) ret += tree[right--];

		left /= 2;
		right /= 2;
	}

	return ret;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	scanf("%d", &N);

	int skill;
	for (int i = 0; i < N; i++) {
		scanf("%d", &skill);
		skills.push_back({ i, skill });
	}

	sort(skills.begin(), skills.end(), cmp);

	init();

	for (int i = 0; i < N; i++) {
		int idx = skills[i].first;
		update(idx, 1);
		answers[idx] = query(0, idx);
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", answers[i]);
	}

	return 0;
}