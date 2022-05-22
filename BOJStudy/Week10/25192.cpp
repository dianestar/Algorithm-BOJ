#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    string str;
    unordered_map<string, int> record;
    for (int i=0; i<N; i++) {
        cin >> str;
        if (str == "ENTER") {
            record.clear();
        }
        else {
            if (record[str] == 0) {
                count++;
            }
            record[str]++;
        }
    }

    cout << count;

    return 0;
}