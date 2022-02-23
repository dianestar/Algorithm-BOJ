#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getDivisors(int num) {
    vector<int> divisors;
    for (int i=1; i<=num; i++) {
        if (num%i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<int> divisors = getDivisors(yellow); // yellow의 약수 구하기
    
    int count = divisors.size();
    int maxIdx;
    if (count%2 == 1) { // 약수의 개수가 홀수인 경우
        maxIdx = (count-1)/2;
    }
    else { // 약수의 개수가 짝수인 경우
        maxIdx = count/2;
    }
    
    for (int i=0; i<maxIdx; i++) {
        /* cf) 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다. */
        int yellowWidth = divisors[count-1-i];
        int yellowHeight = divisors[i];
        
        if (2*(yellowWidth+yellowHeight)+4 == brown) {
            answer.push_back(yellowWidth+2);
            answer.push_back(yellowHeight+2);
            break;
        }
    }
    
    if (answer.size() == 0) { // 약수의 개수가 홀수인 경우 중 for문에서 탐색하지 않은 나머지 하나의 약수가 yellowWidth이자 yellowHeight일 경우
        answer.push_back(divisors[maxIdx]+2);
        answer.push_back(divisors[maxIdx]+2);
    }
    
    return answer;
}

int main() {
    vector<int> brown = {10, 8, 24};
    vector<int> yellow = {2, 1, 24};

    vector<vector<int>> answer = { solution(brown[0], yellow[0]), solution(brown[1], yellow[1]), solution(brown[2], yellow[2]) };

    for (int i=0; i<answer.size(); i++) {
        for (int j=0; j<answer[i].size(); j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}