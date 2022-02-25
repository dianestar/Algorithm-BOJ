#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parents;

bool cmp(const vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int getParent(int x) {
    if (parents[x] == x) { return x; }
    return parents[x] = getParent(parents[x]);
}

void unionNodes(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x < y) { parents[y] = x; }
    else { parents[x] = y; }
}

// Solution #1 Kruskal's Algorithm 활용
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 부모 노드 담는 벡터 초기화
    for (int i=0; i<n; i++) { parents.push_back(i); }
    
    // 건설 비용이 적은 순으로 정렬
    sort(costs.begin(), costs.end(), cmp); 

    int size = costs.size();
    for (int i=0; i<size; i++) {
        int first = costs[i][0]; // 첫 번째 섬의 번호
        int second = costs[i][1]; // 두 번째 섬의 번호
        
        // 아직 통행이 불가능할 경우 (부모 노드가 다른 경우)
        if (getParent(first) != getParent(second)) {
            unionNodes(first, second); // 다리 건설
            answer += costs[i][2]; // 비용 추가
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