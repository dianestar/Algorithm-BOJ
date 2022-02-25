#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int id; // 섬의 번호
    int cost; // 비용
};

struct Cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.cost > b.cost;
    }
};

vector<bool> visited(100, false);

// Solution #2 Prim's Algorithm 활용
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    priority_queue<Node, vector<Node>, Cmp> minHeap; // 비용이 적은 순으로 정렬되는 최소힙
    minHeap.push({0, 0}); // 0번 섬을 기준으로 탐색 시작
    int size = costs.size();
    while (!minHeap.empty()) {
        Node curNode = minHeap.top();
        minHeap.pop();

        if (visited[curNode.id]) {
            // 이미 방문한 섬일 경우 스킵
            continue;
        }

        visited[curNode.id] = true;
        answer += curNode.cost;

        for (int i=0; i<size; i++) {
            // 인접한 섬들의 번호와 다리 건설 비용 minHeap에 push
            if (costs[i][0] == curNode.id) {
                minHeap.push({costs[i][1], costs[i][2]});
            }
            else if (costs[i][1] == curNode.id) {
                minHeap.push({costs[i][0], costs[i][2]});
            }
        }
    }

    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> costs = {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}};
    int answer = solution(n, costs);
    printf("%d", answer);
    
    return 0;
}