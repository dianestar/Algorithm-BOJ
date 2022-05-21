#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string book;
    map<string, int> bookList;
    for (int i=0; i<N; i++) {
        cin >> book;
        bookList[book]++;
    }

    int maxNum = 0;
    string maxBook;
    for (auto iter=bookList.begin(); iter!=bookList.end(); iter++) {
        if (iter->second > maxNum) {
            maxNum = iter->second;
            maxBook = iter->first;
        }
    }

    cout << maxBook;

    return 0;
}