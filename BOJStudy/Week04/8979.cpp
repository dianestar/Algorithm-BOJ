#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Country {
    int id;
    int gold;
    int silver;
    int bronze;
};

bool cmp(const Country &a, const Country &b) {
    if (a.gold == b.gold) {
        if (a.silver == b.silver) {
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<Country> countries(N);
    for (int i=0; i<N; i++) {
        scanf("%d %d %d %d", &countries[i].id, &countries[i].gold, &countries[i].silver, &countries[i].bronze);
    }

    sort(countries.begin(), countries.end(), cmp);

    int rank;
    for (int i=0; i<N; i++) {
        if (countries[i].id == K) {
            rank = i;
            break;
        }
    }
    
    for (int i=rank; i>=0 ;i--) {
        if (i != 0 && countries[i].gold == countries[i-1].gold && countries[i].silver == countries[i-1].silver && countries[i].bronze == countries[i-1].bronze) {
            rank--;
        }
        else {
            break;
        }
    }
        
    printf("%d", rank+1);

    return 0;
}