#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string word;
int len;
vector<string> candidates;

void reverseWord(pair<int, int> pivot) {
    string temp = word;

    // 세 단어로 나누고 뒤집기
    reverse(temp.begin(), temp.begin() + pivot.first);
    reverse(temp.begin() + pivot.first, temp.begin() + pivot.second);
    reverse(temp.begin() + pivot.second, temp.end());

    candidates.push_back(temp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> word;
    len = word.size();

    // next_permuation을 활용한 조합을 통해
    // 0, 1, 2, 3, ... , len-2번째 인덱스 알파벳 다음 중에서 단어를 쪼갤 두 군데 선택
    vector<int> isSelected;
    for (int i=0; i<len-3; i++) { isSelected.push_back(0); }
    for (int i=0; i<2; i++) { isSelected.push_back(1); }
    do {
        pair<int, int> pivot = {-1, -1};
        for (int i=0; i<len-1; i++) {
            if (isSelected[i]) {
                if (pivot.first == -1) { pivot.first = i+1; }
                else { pivot.second = i+1; }
            }
        }
        reverseWord(pivot);
    } while (next_permutation(isSelected.begin(), isSelected.end()));

    //  만들 수 있는 단어 중에서 사전순으로 가장 앞서는 단어를 출력
    sort(candidates.begin(), candidates.end());
    cout << candidates[0];

    return 0;
}