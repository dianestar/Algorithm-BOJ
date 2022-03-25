#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// Solution #2) stringstream 활용
/*
vector<string> split(string str, char delim) {
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delim)) {
        answer.push_back(temp);
    }

    return answer;
}
*/

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string, string>> actionIdVec; // {action, uid}
    unordered_map<string, string> uidNameMap; // {uid: name}
    int N = record.size();
    for (int i=0; i<N; i++) {
        // vector<string> splitVec = split(record[i], ' ');
        vector<string> splitVec;
        stringstream ss(record[i]);
        string temp;
        while (ss >> temp) {
            splitVec.push_back(temp);
        }
        actionIdVec.push_back({splitVec[0], splitVec[1]});           
        if (splitVec[0] != "Leave") {
            uidNameMap[splitVec[1]] = splitVec[2];
        }
    }

    for (int i=0; i<N; i++) {
        string result = "";
        result += uidNameMap[actionIdVec[i].second];
        if (actionIdVec[i].first == "Enter") { result +=  "님이 들어왔습니다."; }
        else if (actionIdVec[i].first == "Leave") { result += "님이 나갔습니다."; }
        else if (actionIdVec[i].first == "Change") { continue; }
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