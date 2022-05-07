#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    string name;
    unordered_map<string, int> nameIdMap;
    unordered_map<int, string> idNameMap;
    for (int i=0; i<N; i++) {
        cin >> name;
        nameIdMap.insert({name, i+1});
        idNameMap.insert({i+1, name});
    }

    string query;
    for (int i=0; i<M; i++) {
        cin >> query;
        if (query[0] - '0' < 10) {
            cout << idNameMap[stoi(query)] << "\n";
        }
        else {
            cout << nameIdMap[query] << "\n";
        }
    }

    return 0;
}