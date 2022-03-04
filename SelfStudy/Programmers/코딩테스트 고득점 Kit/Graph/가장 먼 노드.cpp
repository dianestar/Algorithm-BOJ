#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> yesEdge(20001, vector<bool>(20001, false));
vector<bool> visited(20001, false);
int maxDist;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    int size = edge.size();
    for (int i=0; i<size; i++) {
        yesEdge[edge[i][0]][edge[i][1]] = true;
        yesEdge[edge[i][1]][edge[i][0]] = true;
    }
    
    int curDist = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        curDist++;
        bool noWay = true;
        int size = q.size();
        for (int i=0; i<size; i++) {
            int cur = q.front();
            q.pop();
            
            for (int i=1; i<=n; i++) {
                if (i == cur) { continue; }
                if (yesEdge[cur][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    noWay = false;
                }
            }
            
            if (noWay) {
                if (curDist > maxDist) {
                    maxDist = curDist;
                    answer = 1;
                }
                else if (curDist == maxDist) {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}

int main() {
    int n = 6;
    vector<vector<int>> edge = {{3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2}};

    printf("%d", solution(n, edge));

    return 0;
}