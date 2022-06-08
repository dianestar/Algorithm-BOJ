#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    unordered_map<string, int> dict;

    // 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for (char alpha='A'; alpha<='Z'; alpha++) {
        string key = "";
        key += alpha;
        dict[key] = alpha-'A'+1;
    }

    string temp = "";
    int nextIdx = 27;
    for (int i=0; i<msg.size(); i++) {
        // 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
        temp += msg[i];
        while (dict[temp]) {
            i++;
            temp += msg[i];
        }

        // 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
        dict[temp] = nextIdx;
        nextIdx++;

        // w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
        i--;
        temp.pop_back();
        answer.push_back(dict[temp]);
        temp = "";
    }

    return answer;
}

int main() {
    vector<string> msg = {"KAKAO", "TOBEORNOTTOBEORTOBEORNOT", "ABABABABABABABAB"};

    for (int i=0; i<msg.size(); i++) {
        vector<int> answer = solution(msg[i]);
        for (int j=0; j<answer.size(); j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }

    return 0;
}