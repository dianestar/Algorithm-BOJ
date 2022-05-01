#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> wordList(6);
    for (int i=0; i<6; i++) {
        cin >> wordList[i];
    }
    
    vector<string> candidates; // 퍼즐 후보를 담는 벡터
    do {
        string str = "";
        vector<string> vec; 

        // next_permutation으로 구한 순열의 앞에서부터 세 단어를 가로로 하는 퍼즐 구성
        for (int i=0; i<3; i++) {
            str += wordList[i];
            vec.push_back(wordList[i]);
        }
        
        vector<string> sero; // 현재 퍼즐의 세로를 구성하는 세 단어를 담는 벡터
        bool isValid = true;
        for (int i=0; i<3; i++) { // 퍼즐의 열
            string temp = "";
            for (int j=0; j<3; j++) { // 퍼즐의 행
                // 같은 열 다른 행의 문자들을 넣어 하나의 세로 단어 구하기
                temp += vec[j][i]; 
            }
            sero.push_back(temp);
        }

        // next_permuation으로 구한 순열의 뒤에서부터 세 단어와 퍼즐의 세로를 구성하는 세 단어 비교
        for (int i=3; i<6; i++) {
            auto iter = find(sero.begin(), sero.end(), wordList[i]);
            // 퍼즐의 세로 단어에 없을 경우 valid 하지 않은 퍼즐임을 표시하고 break
            if (iter == sero.end()) {
                isValid = false;
                break;
            }
            // 퍼즐의 세로 단어에 있을 경우 퍼즐의 세로 단어에서 매칭되는 해당 단어 erase
            else {
                sero.erase(iter);
            }
        }

        // valid한 퍼즐인 경우 candidates 벡터에 push
        if (isValid) {
            candidates.push_back(str);
        }
    } while (next_permutation(wordList.begin(), wordList.end()));

    // 6개 단어를 3*3 가로 세로 퍼즐에 놓을 수 없다면 0을 출력한다. 
    if (candidates.size() == 0) {
        cout << 0;
    }
    else {
        // 만약 가능한 답이 여러개라면 사전순으로 앞서는 것을 출력한다.     
        sort(candidates.begin(), candidates.end());

        for (int i=0; i<9; i++) {
            cout << candidates[0][i];
            if (i % 3 == 2) { cout << "\n"; }
        }
    }
    
    return 0;
}