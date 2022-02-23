#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size()-k; // k개의 수를 제거했을 때 얻을 수 있는 숫자의 길이

    int maxIndex = 0;
    for (int i=0; i<len; i++) { // len 길이 만큼의 숫자 만들기

        // 최대 k개를 삭제할 수 있으므로 앞에서부터 k+1개의 원소 중 최댓값을 구하여
        // 최댓값은 answer에 더해주고 최댓값 이외의 나머지 값들은 제거하는 방식
        char maxDigit = number[maxIndex];
        for (int j=maxIndex; j<=i+k; j++) {
            if (number[j] > maxDigit) {
                maxDigit = number[j];
                maxIndex = j;
            }
        }
        answer += maxDigit;

        maxIndex++; // 이 다음 턴에는 현재 answer에 더한 maxDigit의 다음 원소부터 탐색
    }

    return answer;
}

int main() {
    vector<string> number = {"1924","1231234","4177252841"};
    vector<int> k = {2,3,4};

    for (int i=0; i<number.size(); i++) {
        cout << solution(number[i], k[i]) << endl;
    }

    return 0;
}