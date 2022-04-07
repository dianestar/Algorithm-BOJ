#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string name;
    unordered_map<string, int> um;
    for (int i=0; i<N; i++) {
        cin >> name;
        um[name]++;
    }
    for (int i=0; i<M; i++) {
        cin >> name;
        um[name]++;
    }

    int answer = 0;
    vector<string> v;
    for (auto iter=um.begin(); iter!=um.end(); iter++) {
        if (iter->second == 2) {
            answer++;
            v.push_back(iter->first);
        }
    }
    sort(v.begin(), v.end());

    cout << answer << "\n";
    for (int i=0; i<answer; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}