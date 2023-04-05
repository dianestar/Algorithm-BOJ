#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void recursion(int n, int from, int temp, int to) {
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }
    
    // a. 1번 기둥에 있는 n개 중 n-1개의 원반을 (3번 기둥을 거쳐) 2번 기둥으로 옮긴다
    recursion(n-1, from, to, temp);  
    // b. 1번 기둥에 남아 있는 가장 큰 원판을 3번 기둥으로 옮긴다
    answer.push_back({from, to});
    // c. 2번 기둥에 남아 있는 n-1개의 원반을 (1번 기둥을 거쳐) 3번 기둥으로 옮긴다
    recursion(n-1, temp, from, to);

}

vector<vector<int>> solution(int n) {
    // 1번 기둥에 있는 n개의 원판을 3번 원판으로 옮기기
    recursion(n, 1, 2, 3);
    
    return answer;
}

int main() {
    solution(2);

    for (int i=0; i<answer.size(); i++) {
        for (int j=0; j<answer[i].size(); j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}