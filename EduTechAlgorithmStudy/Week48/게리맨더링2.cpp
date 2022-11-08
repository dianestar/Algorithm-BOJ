#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 21

int N;
int allPeople = 0;
int answer = 2147483647;
vector<vector<int>> A(MAX_N, vector<int>(MAX_N));
vector<int> people(5);

bool isOutOfRange(int x, int y, int d1, int d2) {
    // d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
    if (x+d1+d2 > N || y-d1 < 1 || y+d2 > N) return true;
    return false;
}

void countFifthPart(int x, int y, int d1, int d2) {
    // 5번 선거구
    people[4] = allPeople - (people[0] + people[1] + people[2] + people[3]);
}

// 1~4번 선거구
bool countRestPart(int x, int y, int d1, int d2) {
    // ranges[i]: i+1 선거구의 {행 시작 인덱스(포함O), 행 종료 인덱스(포함X), 열 시작 인덱스(포함O), 열 종료 인덱스(포함X)}
    // 1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y (< y+1)
    // 2번 선거구: 1 ≤ r ≤ x+d2 (< x+d2+1), y < c ≤ N (< N+1)
    // 3번 선거구: x+d1 ≤ r ≤ N (< N+1), 1 ≤ c < y-d1+d2
    // 4번 선거구: x+d2 < r ≤ N (< N+1), y-d1+d2 ≤ c ≤ N (< N+1
    vector<vector<int>> ranges = {
        {1, x+d1, 1, y+1},
        {1, x+d2+1, y+1, N+1},
        {x+d1, N+1, 1, y-d1+d2},
        {x+d2+1, N+1, y-d1+d2, N+1}
    };

    for (int i=0; i<4; i++) {
        people[i] = 0;
        for (int r=ranges[i][0]; r<ranges[i][1]; r++) {
            for (int c=ranges[i][2]; c<ranges[i][3]; c++) {
                // 경계선을 넘어갈 경우 continue
                if (i == 0 && r >= x && c >= y-(r-x)
                    || i == 1 && r >= x && c <= y+(r-x)
                    || i == 2 &&  r <= x+d1+d2 && c >= y-d1+(r-x-d1)
                    || i == 3 && r <= x+d1+d2 && c <= y+d2-(r-x-d2)
                ) continue;

                people[i] += A[r][c];
            }
        }

        // 선거구는 구역을 적어도 하나 포함해야 함
        if (people[i] == 0) return false;
    }

    return true;
}

// 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값 구하기
void calculateDiff() {
    int maxPeople = 0;
    int minPeople = 2147483647;

    for (int i=0; i<5; i++) {
        if (people[i] > maxPeople) maxPeople = people[i];
        if (people[i] < minPeople) minPeople = people[i];
    }

    int diff = maxPeople - minPeople;
    if (diff < answer) answer = diff;
}

int main() {
    scanf("%d", &N);

    // 구역 (r, c)의 인구는 A[r][c]
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%d", &A[i][j]);
            allPeople += A[i][j];
        }
    }

    // 기준점 (x, y)와 경계의 길이 d1, d2
    for (int x=1; x<=N; x++) {
        for (int y=1; y<=N; y++) {
            for (int d1=1; d1<=N; d1++) {
                for (int d2=1; d2<=N; d2++) {
                    if (isOutOfRange(x, y, d1, d2)) continue;

                    // flag: 1~4번 선거구 구역 수가 모두 유효할 경우 true, 그 외에는 false
                    int flag = countRestPart(x, y, d1, d2);

                    // 구역을 하나도 포함하지 않는 선거구가 있을 경우 continue
                    if (!flag) continue;

                    countFifthPart(x, y, d1, d2);
                    calculateDiff();
                }
            }
        }
    }
    
    printf("%d", answer);

    return 0;
}