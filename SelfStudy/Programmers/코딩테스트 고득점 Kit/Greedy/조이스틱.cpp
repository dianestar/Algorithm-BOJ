#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int N = name.size();

    int move = N-1; // 조이스틱을 왼쪽 또는 오른쪽 한 방향만으로만 움직일 경우 횟수
    for (int i=0; i<N; i++) {
        answer += min(name[i]-'A', 'Z'-name[i]+1); // 위쪽 vs 아래쪽

        // A(위쪽 또는 아래쪽으로의 조이스틱 조작이 필요 없는 경우)가 연속적으로 나타나는 문자열 탐색
        if (name[i+1] == 'A') {
            int idxA = i+1;
            while (idxA < N && name[idxA] == 'A') {
                idxA++;
            }
            int leftMove = i; // name[i] 기준 왼쪽에서 일어나는 조이스틱 조작 횟수
            int rightMove = N-idxA; // A가 연속적으로 나타나는 문자열 기준 오른쪽에서 일어나는 조이스틱 조작 횟수
            move = min(move, leftMove + rightMove + min(leftMove,rightMove)); // 왼쪽 또는 오른쪽으로 움직이는 횟수 업데이트
            
        }
    }
    answer += move;
   
    return answer;
}

int main() {
    vector<string> name = { "JEROEN", "JAN", "JAZ", "ABAAAAAAAAABB" };
    for (int i=0; i<name.size(); i++) {
        printf("%ld\n", solution(name[i]));
    }

    return 0;
}