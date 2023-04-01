#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000001

int N, M;
vector<int> parent;

void init() {
	for (int i = 0; i <= N; i++) parent.push_back(i);
}

int findRoot(int val) {
	if (parent[val] == val) return val;
	return parent[val] = findRoot(parent[val]);
}

void unionValues(int a, int b) {
	int aRoot = findRoot(a);
	int bRoot = findRoot(b);
	parent[bRoot] = aRoot;
}

bool isInSameSet(int a, int b) {
	if (findRoot(a) == findRoot(b)) return true;
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	
	init();

	int cmd, a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd == 0) unionValues(a, b);
		else isInSameSet(a, b) ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}