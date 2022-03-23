#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Road { // edge
    int houseA; // node1
    int houseB; // node2
    int cost; // edge의 가중치
};
vector<int> parents(100001);

bool cmp(const Road &a, const Road &b) {
    return a.cost < b.cost;
}

int getParent(int house) {
    if (parents[house] == house) {
        return house;
    }
    return parents[house] = getParent(parents[house]); // path compression
}

void unionHouses(int houseA, int houseB) {
    int a = getParent(houseA);
    int b = getParent(houseB);
    if (a < b) { parents[b] = a; }
    else { parents[a] = b; }
}

int main() {
    // 집의 개수 N, 길의 개수 M
    int N, M;
    scanf("%d %d", &N, &M);

    // A번 집과 B번 집을 연결하는 길의 유지비가 C
    int A, B, C;
    vector<Road> roads;
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        roads.push_back({A, B, C});
    }

    // Kruskal's Algorithm 활용
    // Road(edge)의 가중치를 기준으로 오름차순 정렬
    sort(roads.begin(), roads.end(), cmp);

    // House(node)의 parents 정보 초기화
    // 처음에는 각자 자기 자신이 parents
    for (int i=1; i<=N; i++) {
        parents[i] = i;
    }

    vector<int> selectedRoads;
    for (int i=0; i<M; i++) {
        // parent가 다르다는 것은 아직 두 House 사이에 경로가 없다는 뜻 (사이클 X)
        if (getParent(roads[i].houseA) != getParent(roads[i].houseB)) {
            // parent를 같게 만들어 하나의 그래프로 합치기
            unionHouses(roads[i].houseA, roads[i].houseB);
            // Road의 가중치 저장
            selectedRoads.push_back(roads[i].cost);
        }
    }

    // 마을 분할
    // 선택된 Road의 가중치 중 가장 큰 가중치를 갖는 Road는 제외하고 가중치 합 구하기
    int count = selectedRoads.size() - 1;
    int answer = 0;
    for (int i=0; i<count; i++) {
        answer += selectedRoads[i];
    }

    // 없애고 남은 길 유지비의 합의 최솟값을 출력
    printf("%d", answer);

    return 0;
}