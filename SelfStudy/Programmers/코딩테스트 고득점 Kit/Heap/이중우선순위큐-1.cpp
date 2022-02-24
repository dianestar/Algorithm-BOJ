#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

// solution #1 deque 활용
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    int size = operations.size();
    string first, second;
    for (int i=0; i<size; i++) {
        first = operations[i].substr(0, 1);
        second = operations[i].substr(2);
        if (first == "I") { // 큐에 주어진 숫자 삽입
            int num = stoi(second);
            dq.push_back(num);
            sort(dq.begin(), dq.end()); // 오름차순 정렬
        }
        else { // first == "D"
            if (dq.empty()) { // 빈 큐에 데이터를 삭제하라는 연산이 주어질 경우 무시
                continue;
            }
            if (second == "1") { // 큐에서 최댓값 삭제
                dq.pop_back();
            }
            else { // second == "-1" 큐에서 최솟값 삭제
                dq.pop_front();
            }
        }
    }
    
    // 큐가 비어있으면 [0,0] 
    int maxNum = 0;
    int minNum = 0;
    if (!dq.empty()) {
        // 큐가 비어있지 않으면 [최댓값, 최솟값]
        maxNum = dq.back();
        minNum = dq.front();
    }
    answer.push_back(maxNum);
    answer.push_back(minNum);
    
    return answer;
}

int main() {
    vector<string> operations1 = {"I 16", "D 1"};
    vector<string> operations2 = {"I 7", "I 5", "I -5", "D -1"};

    vector<int> answer1 = solution(operations1);
    vector<int> answer2 = solution(operations2);

    printf("%d %d\n%d %d\n", answer1[0], answer1[1], answer2[0], answer2[1]);
    
    return 0;
}