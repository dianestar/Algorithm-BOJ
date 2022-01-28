#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
    if (a.second.first == b.second.first) {
        return a.first < b.first;
    }
    else {
        return a.second.first < b.second.first;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    vector<pair<int, pair<int, string>>> v;
    int age;
    char name[101];
    for (int i=0; i<N; i++) {
        scanf("%d %s", &age, name);
        v.push_back(make_pair(i, make_pair(age, name)));
    }

    sort(v.begin(), v.end(), cmp);

    for (int i=0; i<v.size(); i++) {
        printf("%d %s\n", v[i].second.first, v[i].second.second.c_str());
    }

    return 0;
}