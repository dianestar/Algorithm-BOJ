#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string T;
    vector<int> isNeeded(26, 0);
    cin >> T;
    int TLen = T.size();
    for (int i=0; i<TLen; i++) {
        isNeeded[T[i]-'A']++;
    }
    
    int N, C;
    string W;
    vector<pair<int, string>> books;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> C >> W;
        books.push_back({C, W});
    }

    int minCost = INT_MAX;
    for (int i=1; i<=TLen; i++) {
        vector<int> isSelected;
        for (int j=0; j<N-i; j++) { isSelected.push_back(0); }
        for (int j=0; j<i; j++) { isSelected.push_back(1); }
        
        do {
            int cost = 0;
            vector<int> isAvailable(26, 0);

            for (int j=0; j<N; j++) {
                if (isSelected[j]) {
                    cost += books[j].first;
                    int len = books[j].second.size();
                    for (int k=0; k<len; k++) {
                        isAvailable[books[j].second[k]-'A']++;
                    }
                }
            }

            bool flag = true;
            for (int k=0; k<26; k++) {
                if (isAvailable[k] < isNeeded[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (cost < minCost) { minCost = cost; }
            }
        } while (next_permutation(isSelected.begin(), isSelected.end()));
    }

    if (minCost == INT_MAX) { minCost = -1; }

    cout << minCost;

    return 0;
}