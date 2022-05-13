#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int N;
    scanf("%d", &N);

    int start, end;
    vector<pair<int, int>> meetings;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &start, &end);
        meetings.push_back({start, end});
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int count = 1;
    pair<int, int> lastMeeting = meetings[0];
    for (int i=1; i<N; i++) {
        if (meetings[i].first >= lastMeeting.second) {
            count++;
            lastMeeting = {meetings[i].first, meetings[i].second};
        }
    }

    printf("%d", count);

    return 0;
}