#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    unordered_map<int, int> row;
    unordered_map<int, int> col;
    int r, c;
    for (int i=0; i<n; i++) {
        scanf("%d %d", &r, &c);
        row[r]++;
        col[c]++;
    }

    int answer = 0;
    for (auto iter=row.begin(); iter!=row.end(); iter++) {
        if (iter->second >= 2) { answer++; }
    }
    for (auto iter=col.begin(); iter!=col.end(); iter++) {
        if (iter->second >= 2) { answer++; }
    }

    printf("%d", answer);

    return 0;
}