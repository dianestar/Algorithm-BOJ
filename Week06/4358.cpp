#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    string name;
    int count = 0;

    while (getline(cin, name)) {
        m[name]++;
        count++;
    }

    cout << fixed;
    cout.precision(4);
    for (auto& iter : m) {
        cout << iter.first << " " << iter.second / (double)count * 100 << endl;
    }

    return 0;
}