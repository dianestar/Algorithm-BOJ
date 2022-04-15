#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; // 비밀번호의 길이, 선견지명으로 알게된 비밀번호에 들어가는 수의 개수 
int pwCount; // 가능한 모든 비밀번호의 개수
vector<int> partialPW;
vector<int> pw;

void search(int len) {
    if (len == n) {
        for (int i=0; i<m; i++) { // 선견지명 숫자 벡터 순회
            // 선견지명 숫자가 포함되지 않은 경우
            if (find(pw.begin(), pw.end(), partialPW[i]) == pw.end()) { 
                return;
            }
        }

        // 선견지명 숫자가 포함된 경우
        pwCount++; 
        return;
    }

    for (int i=0; i<10; i++) {
        pw.push_back(i);
        search(len+1);
        pw.pop_back(); // 백트래킹
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    int num;
    for (int i=0; i<m; i++) {
        scanf("%d", &num);
        partialPW.push_back(num);
    }

    search(0);

    printf("%d", pwCount);

    return 0;
}