#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAX_IDX 101

// 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬
// 정렬된 결과를 배열에 넣을 때는, 수와 등장 횟수를 모두 넣으며, 순서는 수가 먼저
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);

    // 배열의 인덱스는 1부터 시작
    vector<vector<int>> A(MAX_IDX, vector<int>(MAX_IDX));
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int row = 3;
    int col = 3;
    int answer = 0;
    while (A[r][c] != k && answer <= 100) {
        // R 연산: 배열 A의 모든 행에 대해서 정렬을 수행 (행의 개수 ≥ 열의 개수인 경우)
        if (row >= col) {
            vector<int> sizes;
            for (int i=1; i<=row; i++) {
                unordered_map<int, int> counter;
                for (int j=1; j<=col; j++) {
                    if (A[i][j] != 0) counter[A[i][j]]++;
                }

                vector<pair<int, int>> counterVec(counter.begin(), counter.end());
                sort(counterVec.begin(), counterVec.end(), cmp);

                // 행 또는 열의 크기가 커진 곳에는 0이 채워진다.
                for (int j=1; j<=col; j++) A[i][j] = 0;

                int idx = 1;
                for (int j=0; j<counterVec.size(); j++) {
                    // 행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다
                    if (idx > 100) break;

                    A[i][idx] = counterVec[j].first;
                    idx++;
                    A[i][idx] = counterVec[j].second;
                    if (j != counterVec.size()-1) idx++;
                }
                sizes.push_back(idx);
            }
            // R 연산이 적용된 경우에는 가장 큰 행을 기준으로 모든 행의 크기가 변한다
            sort(sizes.begin(), sizes.end(), greater<>());
            col = sizes[0];
        }

        // C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한 (행의 개수 < 열의 개수인 경우)
        else {
            vector<int> sizes;
            for (int i=1; i<=col; i++) {
                unordered_map<int, int> counter;
                for (int j=1; j<=row; j++) {
                    if (A[j][i] != 0) counter[A[j][i]]++;
                }

                vector<pair<int, int>> counterVec(counter.begin(), counter.end());
                sort(counterVec.begin(), counterVec.end(), cmp);

                // 행 또는 열의 크기가 커진 곳에는 0이 채워진다.
                for (int j=1; j<=row; j++) A[j][i] = 0;

                int idx = 1;
                for (int j=0; j<counterVec.size(); j++) {
                    // 행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다
                    if (idx > 100) break;

                    A[idx][i] = counterVec[j].first;
                    idx++;
                    A[idx][i] = counterVec[j].second;
                    if (j != counterVec.size()-1) idx++;
                }
                sizes.push_back(idx);
            }
            // C 연산이 적용된 경우에는 가장 큰 열을 기준으로 모든 열의 크기가 변한다
            sort(sizes.begin(), sizes.end(), greater<>());
            row = sizes[0];
        }

        answer++;
    }

    // A[r][c]에 들어있는 값이 k가 되기 위한 최소 시간을 출력
    // 100초가 지나도 A[r][c] = k가 되지 않으면 -1을 출력
    if (answer > 100) { answer = -1; }
    printf("%d", answer);

    return 0;
}