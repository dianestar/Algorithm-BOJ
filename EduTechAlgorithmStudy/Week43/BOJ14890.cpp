#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int L;
int answer;

bool isOutOfRange(int idx) {
    if (idx < 0 || idx >= N) { return true; }
    return false;
}

void checkRoad(vector<vector<int>> road) {
    // i) 경사로를 놓은 곳에 또 경사로를 놓는 경우, 경사로 ❌
    vector<vector<int>> isInstalled(N, vector<int>(N, 0)); // 경사로 설치 여부 체크
    for (int i=0; i<N; i++) {
        bool isValid = true; // 지나갈 수 있는 길인지 여부

        for (int j=1; j<N; j++) {
            // ii) 낮은 칸과 높은 칸의 높이 차이가 1이 아닌 경우, 경사로 ❌
            if (abs(road[i][j] - road[i][j-1]) > 1) {
                isValid = false;
                break;
            }

            // 하향 경사로
            else if (road[i][j-1] - road[i][j] == 1) {
                if (isInstalled[i][j]) {
                    isValid = false;
                    break;
                }
                isInstalled[i][j] = 1;

                // iii) 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우, 경사로 ❌
                for (int k=1; k<L; k++) {
                    j++;
                    if (isInstalled[i][j] || road[i][j] != road[i][j-1]) {
                        isValid = false;
                        break;
                    }
                    isInstalled[i][j] = 1;
                }

                // iv) 경사로를 놓다가 범위를 벗어나는 경우, 경사로 ❌
                if (!isOutOfRange(j+1) && road[i][j+1] > road[i][j]) {
                    isValid = false;
                    break;
                }
            }

            // 상향 경사로
            else if (road[i][j] - road[i][j-1] == 1) {
                // 지나온 낮은 지점들을 다시 탐색
                j--;
                if (isInstalled[i][j]) {
                    isValid = false;
                    break;
                }
                isInstalled[i][j] = 1;

                /// iii) 낮은 지점의 칸의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우, 경사로 ❌
                for (int k=1; k<L; k++) {
                    j--;
                    if (isInstalled[i][j] || road[i][j] != road[i][j+1]) {
                        isValid = false;
                        break;
                    }
                    isInstalled[i][j] = 1;
                }

                // iv) 경사로를 놓다가 범위를 벗어나는 경우, 경사로 ❌
                if (!isOutOfRange(j-1) && road[i][j-1] > road[i][j]) {
                    isValid = false;
                    break;
                }

                // 원래 탐색 중이던 위치로 복귀
                j += L;
            }
            
        }

        if (isValid) { answer++; }
    }
}

int main() {
    // N (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)
    // 길의 개수는 2N (4 <= 2N <= 200)
    scanf("%d %d", &N, &L);

    vector<vector<int>> origin(N, vector<int>(N)); // 행 탐색용 벡터
    vector<vector<int>> reversed(N, vector<int>(N)); // 열 탐색용 벡터

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &origin[i][j]);
            reversed[j][i] = origin[i][j];
        }
    }
    
    checkRoad(origin);
    checkRoad(reversed);

    printf("%d\n", answer);

    return 0;
}