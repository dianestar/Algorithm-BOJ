#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, K;
vector<string> strList;

// 학생들이 읽을 수 있는 단어 개수의 최댓값
int maxCount;

// cf) 남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 
vector<char> defaultList = { 'a', 'n', 't', 'i', 'c' };

// key: 알파벳 아스키코드 - 'a' 값 (즉 key 0번은 'a'를 의미), value: 0일 경우 가르치지 않음 1일 경우 가르침
unordered_map<int, bool> teachingMap;

void input() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		char str[16];
		scanf("%s", str);
		strList.push_back(str);
	}
}

bool isReadAble(string str) {
	int len = str.size() - 4;
	for (int i = 4; i < len; i++) {
		// 한 알파벳이라도 가르치지 않은 경우 읽을 수 없음
		if (teachingMap[str[i] - 'a'] == 0) {
			return false;
		}
	}
	// 읽을 수 있음
	return true;
}

void dfs(int idx, int count) {
	// 가르칠 수 있는 알파벳 개수를 모두 사용한 경우 or 가르칠 후보 알파벳이 바닥난 경우 탈출
	if (count == 0) {
		// 이번 경우 학생들이 읽을 수 있는 단어의 개수 카운트
		int curCount = 0;
		for (int i = 0; i < N; i++) {
			if (isReadAble(strList[i])) {
				curCount++;
			}
		}

		// maxCount 값 업데이트
		if (curCount > maxCount) {
			maxCount = curCount;
		}

		return;
	}

	if (idx >= 26) return;

	// 백트래킹 활용하여 조합 구하기
	if (!teachingMap[idx]) {
		teachingMap[idx] = true;
		dfs(idx + 1, count - 1);
		teachingMap[idx] = false;
	}

	// 현재 알파벳을 패스하는 경우의 수 살펴보기
	dfs(idx + 1, count);
}

void solution() {
	// a, n, t, i, c 최소 5개의 글자는 알아야 어떤 단어든 읽을 수 있음
	if (K < 5) return;

	K -= 5;
	for (int i = 0; i < 5; i++) {
		teachingMap[defaultList[i] - 'a'] = true;
	}

	dfs(0, K);
}

void print() {
	printf("%d", maxCount);
}

int main() {
	input();
	solution();
	print();

	return 0;
}