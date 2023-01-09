#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX_N 15

int N, answer;
vector<int> col(MAX_N);

void setQueen(int row) {
	// 퀸은 행 당 하나다. 모든 행이 채워진 경우, 방법의 수++
	if (row == N) {
		answer++;
		return;
	}
	
	for (int j = 0; j < N; j++) {
		bool flag = true;

		for (int i = 0; i < row; i++) {
			// 이미 놓여진 Queen이 i) 같은 열에 존재하거나 ii) 대각선에 존재할 경우 invalid
			if (col[i] == j || (row - i) == abs(j - col[i])) {
				flag = false;
				break;
			}
		}

		// valid한 열 위치 정보 저장 후 다음 행으로 이동
		if (flag) {
			col[row] = j;
			setQueen(row + 1);
		}
	}
}

int main() {
	// cf) 퀸은 자신을 기준으로 상하좌우 + 대각선으로 이동 및 공격 가능
	scanf("%d", &N);
	setQueen(0);
	printf("%d", answer);

	return 0;
}