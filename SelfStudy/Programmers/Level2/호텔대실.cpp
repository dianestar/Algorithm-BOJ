#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_ROOM 1001

vector<pair<int, int>> timeByMin;
vector<int> used(MAX_ROOM);

int convertTime(string strTime) {
    int hh = stoi(strTime.substr(0, 2));
    int mm = stoi(strTime.substr(3, 2));
    return hh * 60 + mm;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int solution(vector<vector<string>> book_time) {
    int len = book_time.size();
    for (int i=0; i<len; i++) {
        timeByMin.push_back({convertTime(book_time[i][0]), convertTime(book_time[i][1])});
    }
    sort(timeByMin.begin(), timeByMin.end(), cmp);
   
    int answer = 1;
    bool flag;
    used[0] = timeByMin[0].second;
    for (int i=1; i<len; i++) {
        flag = false;
        for (int j=0; j<answer; j++) {
            if (used[j] + 10 <= timeByMin[i].first) {
                used[j] = timeByMin[i].second;
                flag = true;
                break;
            }
        }
        if (!flag) {
            used[answer] = timeByMin[i].second;
            answer++;
        }
    }
    
    return answer;
}