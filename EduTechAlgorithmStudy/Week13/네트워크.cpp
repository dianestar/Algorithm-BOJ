#include <iostream>
#include <string>
#include <vector>

using namespace std;

void search(int i, vector<int> &visited, vector<vector<int>> computers) {
    if (i == visited.size()) {
        return;
    }
    visited[i] = 1;
    for (int j=0; j<visited.size(); j++) {
        if (j != i && !visited[j] && computers[i][j] == 1) {
            search(j, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> visited;
    for (int i=0; i<n; i++) {
        visited.push_back(0);
    }
    for (int i=0; i<n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        else {
            answer++;
            search(i, visited, computers);
        }
    }
    
    return answer;
}

int main() {
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    printf("%d", solution(n, computers));

    return 0;
}