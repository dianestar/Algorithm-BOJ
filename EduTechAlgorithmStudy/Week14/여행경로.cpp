#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;

void search(vector<vector<string>> &tickets, vector<int> &used, string curr) {
    if (answer.size() == tickets.size() + 1) {
        return;
    }
    
    for (int i=0; i<tickets.size(); i++) {
        if (tickets[i][0] == curr && !used[i]) {
            used[i] = 1;
            search(tickets, used, tickets[i][1]);
        }
    }
    
    answer.push_back(curr);
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<int> used(tickets.size(), 0);

    sort(tickets.begin(), tickets.end());
    search(tickets, used, "ICN");
    reverse(answer.begin(), answer.end());
    
    return answer;
}

int main() {
    vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};

    vector<string> s = solution(tickets);
    for (int i=0; i<s.size(); i++) {
        cout << s[i] << endl;
    }
    
    return 0;
}