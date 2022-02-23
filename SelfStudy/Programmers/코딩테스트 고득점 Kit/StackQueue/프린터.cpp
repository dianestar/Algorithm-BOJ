#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    for (int i=0; i<priorities.size(); i++) {
        q.push({i, priorities[i]});
    }
    
    sort(priorities.begin(), priorities.end(), cmp);
    int targetPrio = priorities[0];
    int count = 0;
    while (!q.empty()) {
        if (q.front().second == targetPrio) {
            count++;
            if (q.front().first == location) {
                answer = count;
                break;
            }
            targetPrio = priorities[count];
            q.pop();
        }
        else {
            auto goBack = q.front();
            q.pop();
            q.push(goBack);
        }
    }
    
    return answer;
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;

    printf("%d", solution(priorities, location));
    
    return 0;
}