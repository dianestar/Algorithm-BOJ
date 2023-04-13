#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> routes;

void move(int N, int from, int to, int temp) {
    if (N == 1) {
        routes.push_back({from, to});
        return;
    }

    move(N-1, from, temp, to);
    move(1, from, to, temp); 
    move(N-1, temp, to, from);
}

int main() {
    int N;
    scanf("%d", &N);

    move(N, 1, 3, 2);

    printf("%d\n", routes.size());
    for (int i=0; i<routes.size(); i++) {
        printf("%d %d\n", routes[i].first, routes[i].second);
    }

    return 0;
}