#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string strA, strB;
    cin >> strA >> strB;

    int lenA = strA.size();
    int lenB = strB.size();

    vector<vector<int>> LCS(lenA+1, vector<int>(lenB+1, 0));
    for (int i=1; i<=lenA; i++) {
        for (int j=1; j<=lenB; j++) {
            if (strA[i-1] == strB[j-1]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    printf("%d", LCS[lenA][lenB]);

    return 0;
}