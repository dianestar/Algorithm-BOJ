#include <iostream>
#include <deque>
using namespace std;

struct Node {
	int id;
	int val;
};

int N, L;
deque<Node> dq;

int main() {
	scanf("%d %d", &N, &L);

	int num;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		
		while (!dq.empty() && dq.front().id < i - L + 1) {
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().val > num) {
			dq.pop_back();
		}

		dq.push_back({ i, num });

		printf("%d ", dq.front().val);
	}

	return 0;
}