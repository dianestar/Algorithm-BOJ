#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long answer;
vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
vector<int> sumAB;
vector<int> sumCD;

int main() {
    scanf("%d", &N);

    int a, b, c, d;
    for (int i=0; i<N; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);

        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    // A+B 합, C+D 합 구하기 
    // worst case: 4000 * 4000 가능
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            sumAB.push_back(A[i] + B[j]);
            sumCD.push_back(C[i] + D[j]);
        }
    }

    // 오름차순 정렬
    sort(sumAB.begin(), sumAB.end());
    sort(sumCD.begin(), sumCD.end());

    // 투포인터 활용
    int len = sumAB.size();
    int start = 0;
    int end = len - 1;
    while (start < len && end >= 0) {
        int curAB = sumAB[start];
        int curCD = sumCD[end];
        int sum = curAB + curCD;

        if (sum == 0) {
            long long countAB = 0;
            long long countCD = 0;

            while (start < len && sumAB[start] == curAB) {
                start++;
                countAB++;
            }
            while (end >= 0 && sumCD[end] == curCD) {
                end--;
                countCD++;
            }

            // 1 <= countAB <= 4,000 * 4,000
            // 1 <= countCD <= 4,000 * 4,000
            // 따라서 1 <= answer <= 16,000,000 * 16,000,000 이므로
            // answer는 long long 타입
            answer += countAB * countCD;
        }
        else if (sum > 0) {
            end--;
        }
        else {
            start++;
        }
    }

    printf("%lld", answer);

    return 0;
}