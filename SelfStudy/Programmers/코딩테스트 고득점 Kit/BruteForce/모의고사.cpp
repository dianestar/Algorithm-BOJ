#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) { // 점수가 같을 경우 수포자 번호 기준 오름차순 정렬
        return a < b;
    }
    return a.second > b.second; // 점수 기준 내림차순 정렬
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> first = {1,2,3,4,5}; // 1번 수포자가 찍는 방식
    vector<int> second = {2,1,2,3,2,4,2,5}; // 2번 수포자가 찍는 방식
    vector<int> third = {3,3,1,1,2,2,4,4,5,5}; // 3번 수포자가 찍는 방식
    
    vector<pair<int, int>> scores; // {수포자 번호, 점수}를 담는 벡터
    for (int i=1; i<=3; i++) {
        scores.push_back({i, 0});
    }
    
    for (int i=0; i<answers.size(); i++) { // 문제를 맞힐 때마다 점수 +1
        if (answers[i] == first[i%5]) { scores[0].second++; }
        if (answers[i] == second[i%8]) { scores[1].second++; }
        if (answers[i] == third[i%10]) { scores[2].second++; }
    }
    
    /* cf) 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요. */
    sort(scores.begin(), scores.end(), cmp);
    for (int i=0; i<scores.size(); i++) {
        if (scores[i].second == scores[0].second) {
            answer.push_back(scores[i].first);
        }
    }
    
    return answer;
}

void printAnswer(vector<int> answer) {
    for (int i=0; i<answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
}

int main() {
    vector<int> answers1 = {1,2,3,4,5};
    vector<int> answers2 = {1,3,2,4,2};

    printAnswer(solution(answers1));
    printAnswer(solution(answers2));

    return 0;
}