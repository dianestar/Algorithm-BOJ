#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int strToInt(string str) { // "09:00" -> 540 (분 단위로 변환)
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3, 2));
    return hour * 60 + min;
}

string intToStr(int num) { // 540 -> "09:00" ("HH:MM" 형식으로 변환)
    string str = "";
    int hour = num / 60;
    int min = num % 60;
    
    str += hour < 10 ? "0" + to_string(hour) : to_string(hour);
    str += ":";
    str += min < 10 ? "0" + to_string(min) : to_string(min);
    
    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<pair<int, int>> busTable; // {버스 출발 시간, 버스에 탑승한 크루 수} 저장하는 벡터
    int busStart = strToInt("09:00"); // 셔틀 운행 시작 시간은 09:00
    for (int i=0; i<n; i++) { // n: 셔틀 운행 횟수, t: 셔틀 운행 간격, m: 한 셔틀에 탈 수 있는 최대 크루 수
        busTable.push_back({busStart + i * t, 0});
    }
    
    vector<int> crewTable; // 크루의 도착 시간 timetable을 분 단위로 변환한 벡터
    for (int i=0; i<timetable.size(); i++) {
        crewTable.push_back(strToInt(timetable[i]));
    }
    sort(crewTable.begin(), crewTable.end()); // 오름차순 정렬

    int lastOnCrew = 0; // 마지막으로 버스에 탑승한 크루의 인덱스
    for (int i=0; i<crewTable.size(); i++) { // 크루를 한 명씩 순서대로 버스에 태우기
        for (int j=0; j<busTable.size(); j++) {
            if (crewTable[i] <= busTable[j].first && busTable[j].second < m) {
                busTable[j].second++;
                lastOnCrew = i;
                break;
            }
        }
    }
    
    if (busTable[n-1].second < m) { // i) 마지막 버스에 탑승할 자리가 있다면 
        // 마지막 버스 도착 시간에 콘이 도착하면 됨
        answer = intToStr(busTable[n-1].first);
    } else { // ii) 없다면
        // 마지막으로 탑승한 크루보다 1분 일찍 도착하면 됨
        answer = intToStr(crewTable[lastOnCrew] - 1);
    }

    return answer;
}

int main() {
    vector<int> n = {1, 2, 2, 1, 1, 10};
    vector<int> t = {1, 10, 1, 1, 1, 60};
    vector<int> m = {5, 2, 2, 5, 1, 45};
    vector<vector<string>> timetable = {
        {"08:00", "08:01", "08:02", "08:03"},
        {"09:10", "09:09", "08:00"},
        {"09:00", "09:00", "09:00", "09:00"},
        {"00:01", "00:01", "00:01", "00:01", "00:01"},
        {"23:59"},
        {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"}
    };

    for (int i=0; i<n.size(); i++) {
        cout << solution(n[i], t[i], m[i], timetable[i]) << "\n";
    }

    return 0;
}