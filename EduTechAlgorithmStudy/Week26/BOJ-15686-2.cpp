// Solution #2) next_permutation 활용

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_INT 2147483647
int N, M;
int minCityDistance = MAX_INT;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> selected;

void calculateDistance() {
    int cityDistance = 0;
    for (int i=0; i<house.size(); i++) {
        int minHouseDistance = MAX_INT;
        for (int j=0; j<chicken.size(); j++) {
            if (selected[j] == 1) {
                int houseDistance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                if (houseDistance < minHouseDistance) {
                    minHouseDistance = houseDistance;
                }
            }
        }
        cityDistance += minHouseDistance;
    }
    if (cityDistance < minCityDistance) {
        minCityDistance = cityDistance;
    }
}

void selectChicken() {
    for (int i=0; i<chicken.size()-M; i++) { selected.push_back(0); }
    for (int i=0; i<M; i++) { selected.push_back(1); }
    do {
        calculateDistance();
    } while(next_permutation(selected.begin(), selected.end()));
}

int main() {
    scanf("%d %d", &N, &M);

    int flag;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &flag);
            if (flag == 1) { house.push_back({i, j}); }
            else if (flag == 2) { chicken.push_back({i, j}); }
        }
    }

    selectChicken();
    printf("%d", minCityDistance);

    return 0;
}