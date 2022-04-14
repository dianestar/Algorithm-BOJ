#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string fileName;
    vector<string> v;
    for (int i=0; i<N; i++) {
        cin >> fileName;
        v.push_back(fileName);
    }

    int len = fileName.size();
    string answer = "";
    for (int i=0; i<len; i++) {
        int origin = v[0][i];
        int j;
        for (j=1; j<N; j++) {
            if (v[j][i] != origin) {
                answer += '?';
                break;
            }
        }
        if (j==N) {
            answer += origin;
        }
    }

    cout << answer;

    return 0;
}