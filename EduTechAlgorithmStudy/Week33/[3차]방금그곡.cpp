#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

vector<string> split(string str, char delim) {
    vector<string> answer;
    stringstream ss(str);
    string temp;
    
    while (getline(ss, temp, delim)) {
        answer.push_back(temp);
    }
    
    return answer;
}

/*
vector<string> split(string str, char delim) {
    vector<string> answer;
    
    answer.push_back(str.substr(0, 5));
    answer.push_back(str.substr(6, 5));
    int idx = str.find(",", 12);
    answer.push_back(str.substr(12, idx-12));
    answer.push_back(str.substr(idx+1));
    
    return answer;
}
*/

string changeSharp(string str) {
    string answer = "";
    int answerIdx = 0;
    for (int i=0; i<str.size(); i++) {
        if (str[i] == '#') {
            answer[answerIdx-1] = tolower(str[i-1]);
        }
        else {
            answer += str[i];
            answerIdx++;
        }
    }
    return answer;
}

int getTime(string start, string end) {
    int startHr = stoi(start.substr(0, 2));
    int startMin = stoi(start.substr(3, 2));
    int endHr = stoi(end.substr(0, 2));
    int endMin = stoi(end.substr(3, 2));
    
    return (endHr * 60 + endMin) - (startHr * 60 + startMin);
}

string solution(string m, vector<string> musicinfos) {    
    m = changeSharp(m);
    int N = musicinfos.size();
    
    int maxTime = 0;
    string answer = "(None)";
    
    for (int i=0; i<N; i++) {
        // splitedInfo[0]: 시작시각, [1]: 끝난시각, [2]: 음악제목, [3]: 악보정보
        vector<string> splitedInfo = split(musicinfos[i], ',');
        splitedInfo[3] = changeSharp(splitedInfo[3]);
        
        int time = getTime(splitedInfo[0], splitedInfo[1]);
        int len = splitedInfo[3].size();
        string playedAkbo = "";
        int repeat = time / len;
        int remain = time % len;
        for (int j=0; j<repeat; j++) {
            if (playedAkbo.size() > m.size()) { // 시간 초과 해결 부분
                break;
            }
            playedAkbo += splitedInfo[3];
        }
        playedAkbo += splitedInfo[3].substr(0, remain);
        splitedInfo[3] = playedAkbo;
        
        // 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다.
        // 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
        // 조건이 일치하는 음악이 없을 때에는 “(None)”을 반환한다.
        if (splitedInfo[3].find(m) != string::npos && time > maxTime) {
            answer = splitedInfo[2];
            maxTime = time;
        }
    }
    
    return answer;
}

int main() {
    vector<string> m = {"ABCDEFG", "CC#BCC#BCC#BCC#B", "ABC"};
    vector<vector<string>> musicinfos = {{"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"}, {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"}, {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"}};

    for (int i=0; i<m.size(); i++) {
        cout << solution(m[i], musicinfos[i]) << "\n";
    }

    return 0;
}