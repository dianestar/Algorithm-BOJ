#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) { 
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> coordinate(N);
    for (int i=0; i<N; i++) {
        scanf("%d %d", &coordinate[i].first, &coordinate[i].second);
    }

    sort(coordinate.begin(), coordinate.end(), cmp);

    for (int i=0; i<N; i++) {
        printf("%d %d\n", coordinate[i].first, coordinate[i].second);
    }

    return 0;
}