#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 50

int dr[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dc[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };

int N, houseCount;
int answer = 2147483647;
pair<int, int> postOffice;
vector<vector<char>> charMap(MAX_N, vector<char>(MAX_N));
vector<vector<int>> heightMap(MAX_N, vector<int>(MAX_N));
vector<int> heightValues;

// N * N 맵 행렬 범위 벗어날 경우 체크
bool isOutOfRange(int row, int col) {
	if (row < 0 || row >= N || col < 0 || col >= N) {
		return true;
	}
	return false;
}

// 고도 투포인터 범위 벗어날 경우 체크
bool isOutOfHeight(int h, int startVal, int endVal) {
	if (h < startVal || h > endVal) return true;
	return false;
}

// bfs 활용하여 경로 탐색
bool bfs(int startVal, int endVal) {

	if (isOutOfHeight(heightMap[postOffice.first][postOffice.second], startVal, endVal)) {
		return false;
	}

	queue<pair<int, int>> q;
	q.push(postOffice);

	int curCount = 0;
	vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_N, false));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int d = 0; d < 8; d++) {
			int nextRow = cur.first + dr[d];
			int nextCol = cur.second + dc[d];

			if (isOutOfRange(nextRow, nextCol) || visited[nextRow][nextCol] || isOutOfHeight(heightMap[nextRow][nextCol], startVal, endVal)) {
				continue;
			}

			if (charMap[nextRow][nextCol] == 'K') {
				curCount++;

				if (curCount == houseCount) {
					return true;
				}
			}

			visited[nextRow][nextCol] = true;
			q.push({ nextRow, nextCol });
		}
	}

	return false;
}

int main() {
	scanf("%d", &N);

	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &c);
			charMap[i][j] = c;

			// 우체국은 'P', 집은 'K', 목초지는 '.'
			if (c == 'P') postOffice = { i, j };
			else if (c == 'K') houseCount++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &heightMap[i][j]);
			heightValues.push_back(heightMap[i][j]);
		}
	}

	// 고도 중복 값 제거
	sort(heightValues.begin(), heightValues.end());
	heightValues.erase(unique(heightValues.begin(), heightValues.end()), heightValues.end());
	
	// 투포인터 활용
	int len = heightValues.size();
	int startPt = 0;
	int endPt = 0;
	while (startPt < len && endPt < len) {
		int startVal = heightValues[startPt];
		int endVal = heightValues[endPt];

		if (bfs(startVal, endVal)) {
			int tired = endVal - startVal;
			if (tired < answer) answer = tired;
			startPt++;
		}
		else {
			endPt++;
		}
	}

	printf("%d", answer);

	return 0;
}