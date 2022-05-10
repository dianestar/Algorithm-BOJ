#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<int>> infoMap;   

void makeMap(string originText) {
    vector<vector<string>> splitedInfo(4, vector<string>(2, "-"));

    stringstream ss(originText);
    string temp;
    int score;
    int idx = 0;
    while (ss >> temp) {
        if (idx < 4) { splitedInfo[idx][0] = temp; }
        else { score = stoi(temp); }
        idx++;
    }
    
    string a, b, c, d;
    for (int j=0; j<2; j++) {
        a = splitedInfo[0][j];
        for (int k=0; k<2; k++) {
            b = splitedInfo[1][k];
            for (int l=0; l<2; l++) {
                c = splitedInfo[2][l];
                for (int m=0; m<2; m++) {
                    d = splitedInfo[3][m];
                    infoMap[a+b+c+d].push_back(score);
                }
            }
        }
    }
}

pair<string, int> getQuery(string originText) {
    stringstream ss(originText);
    string temp;
    string str = "";
    int score;
    int idx = 0;
    
    while (ss >> temp) {
        if (temp == "and") { continue; }
        if (idx < 4) { str += temp; }
        else { score = stoi(temp); }
        idx++;
    }
    
    return {str, score};
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
 
    for (int i=0; i<info.size(); i++) {
        makeMap(info[i]);
    }
    
    for (int i=0; i<query.size(); i++) {
        pair<string, int> result = getQuery(query[i]);
        if (infoMap.find(result.first) == infoMap.end()) {
            answer.push_back(0);
        }
        else {
            int count = 0;
            vector<int> candidates = infoMap[result.first];
            for (int i=0; i<candidates.size(); i++) {
                if (candidates[i] >= result.second) { count++; }
            }
            answer.push_back(count);
        }
    }
    
    return answer;
}

int main() {
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<int> answer = solution(info, query);

    for (int i=0; i<answer.size(); i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}