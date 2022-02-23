#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int days;
    queue<int> q;
    for (int i=0; i<progresses.size(); i++) {
        days = ceil((double)(100-progresses[i])/speeds[i]);
        q.push(days);
    }
    
    int count = 1;
    int pivot = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() <= pivot) {
            count++;
        }
        else {
            answer.push_back(count);
            count = 1;
            pivot = q.front();            
        }
        q.pop();
    }
    if (count != 0) {
        answer.push_back(count);
    }
    
    return answer;
}


int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    vector<int> answer = solution(progresses, speeds);
    for (int i=0; i<answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    
    return 0;
}