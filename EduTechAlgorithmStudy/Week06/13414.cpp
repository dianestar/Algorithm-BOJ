#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int K, L;
    scanf("%d %d", &K, &L);

    map<string, int> m;
    char id[9];
    for (int i=1; i<=L; i++) {
        scanf("%s", id);
        m[id] = i;
    }

    vector<pair<int, string>> v;
    for (auto iter=m.begin(); iter!=m.end(); iter++) {
        v.push_back({iter->second, iter->first});
    }

    sort(v.begin(), v.end());

    if (v.size() < K) { K = v.size(); }
    for (int i=0; i<K; i++) {
        printf("%s\n", v[i].second.c_str());
    }
    return 0;
}

    /*
    map<int, string> system;
    for (int i=0; i<L; i++) {
        cin >> id;
        for (auto& pair : system) {
            if (pair.second == id) {
                system.erase(pair.first);
                break;
            }
        }
        system.insert(make_pair(index, id));
        index++;
    }

    int count = 0;
    for (auto iter = system.begin(); iter != system.end(); iter++) {
        if (count == K) {
            break;
        }
        cout << iter->second << endl;
        count++;
    }

    end = clock();
    cout << "time used: " << (double)(end-start) << endl; 

    return 0;
    */
