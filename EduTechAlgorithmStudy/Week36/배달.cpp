#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 500001

struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    // edge 정보 저장
    vector<pair<int, int>> edges[N+1]; // edges[i]: i에 인접한 노드들의 정보, edges[i][j].first: 노드번호, edges[i][j].second: 시간
    for (int i=0; i<road.size(); i++) {
        edges[road[i][0]].push_back({road[i][1], road[i][2]});
        edges[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    // Dijkstra using priority_queue
    vector<int> minTime(N+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // {노드번호, 시간}
    
    minTime[1] = 0;
    pq.push({1, 0});
    
    while (!pq.empty()) {
        int node = pq.top().first;
        int time = pq.top().second;
        pq.pop();
        
        if (minTime[node] < time) { continue; }
        
        for (int i=0; i<edges[node].size(); i++) {
            int adjNode = edges[node][i].first;
            int adjTime = edges[node][i].second;
            
            int passingTime = time + adjTime;
            if (passingTime < minTime[adjNode]) {
                minTime[adjNode] = passingTime;
                pq.push({adjNode, passingTime});
            }
        }
    }
    
    // 최단 시간이 K 시간 이하인 마을의 개수 체크
    for (int i=1; i<=N; i++) {
        if (minTime[i] <= K) {
            answer++;
        }
    }
    
    return answer;
}

int main() {
    /*
    int N = 5;
    vector<vector<int>> road = {{1,2,1}, {2,3,3}, {5,2,2}, {1,4,2}, {5,3,1}, {5,4,2}};
    int K = 3;
    */
    
    int N = 6;
    vector<vector<int>> road = {{1,2,1}, {1,3,2}, {2,3,2}, {3,4,3}, {3,5,2}, {3,5,3}, {5,6,1}};
    int K = 4;
    
    printf("%d\n", solution(N, road, K));

    return 0;
}