#include <iostream>
#include <vector>
using namespace std;

vector<int> parent(51);

int getParent(int id) {
    if (id == parent[id]) { return id; }
    return parent[id] = getParent(parent[id]);
}

void unionParent(int id1, int id2) {
    id1 = getParent(id1);
    id2= getParent(id2);
    parent[id2] = id1;
}

int main() {
    // 입력
    int N, M;
    scanf("%d %d", &N, &M);

    int knowTruth;
    scanf("%d", &knowTruth);
    vector<int> peopleKnowTruth(knowTruth);
    for (int i=0; i<knowTruth; i++) {
        scanf("%d", &peopleKnowTruth[i]);
    }

    int num;
    vector<vector<int>> peoplePerParty(M, vector<int>());
    for (int i=0; i<M; i++) {
        scanf("%d", &num);
        int id;
        for (int j=0; j<num; j++) {
            scanf("%d", &id);
            peoplePerParty[i].push_back(id);
        }
    }

    int answer = M;

    // 이야기의 진실을 아는 사람이 없는 경우
    if (knowTruth == 0) {
        printf("%d", answer);
        return 0;
    }

    // 이야기의 진실을 아는 사람이 있는 경우
    // parent 벡터 초기화
    for (int i=1; i<=N; i++) {
        parent[i] = i;
    }

    // 파티 별로 unionParent
    for (int i=0; i<M; i++) {
        int firstPerson = peoplePerParty[i][0];
        for (int j=1; j<peoplePerParty[i].size(); j++) {
            unionParent(firstPerson, peoplePerParty[i][j]);
        }
    }

    // 진실을 아는 사람의 parent와 parent가 같은 사람이 있는 파티의 경우 answer 카운트에서 제외
    for (int i=0; i<M; i++) {
        bool flag = true;
        for (int j=0; j<peoplePerParty[i].size(); j++) {
            for (int k=0; k<knowTruth; k++) {
                if (getParent(peoplePerParty[i][j]) == getParent(peopleKnowTruth[k])) {
                    flag = false;
                    answer--;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
    }

    printf("%d", answer);
    return 0;
}