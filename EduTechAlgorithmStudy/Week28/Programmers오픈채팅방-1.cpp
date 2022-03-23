#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Solution #1) find & substr 활용
vector<string> solution(vector<string> record) {
    vector<string> answer;

    int N = record.size();
    vector<string> actionVec;
    vector<string> uidVec;
    unordered_map<string, string> uidMap;

    for (int i=0; i<N; i++) {
        int firstDelim = record[i].find(' ');
        string action = record[i].substr(0, firstDelim);
        actionVec.push_back(action);

        string uid;
        if (action == "Leave") {
            uid = record[i].substr(firstDelim+1);
        }
        else {
            int secondDelim = record[i].find(' ', firstDelim+1);
            uid = record[i].substr(firstDelim+1, secondDelim-firstDelim-1);
            string nickname = record[i].substr(secondDelim+1);
            uidMap[uid] = nickname;
        }
        uidVec.push_back(uid);
    }

    for (int i=0; i<N; i++) {
        string result = "";
        result += uidMap[uidVec[i]];
        if (actionVec[i] == "Enter") { result +=  "님이 들어왔습니다."; }
        else if (actionVec[i] == "Leave") { result += "님이 나갔습니다."; }
        else if (actionVec[i] == "Change") { continue; }
        answer.push_back(result);
    }
    
    return answer;
}

int main() {
    vector<string> record = {
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"
    };
    
    vector<string> answer = solution(record);

    for (int i=0; i<answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}