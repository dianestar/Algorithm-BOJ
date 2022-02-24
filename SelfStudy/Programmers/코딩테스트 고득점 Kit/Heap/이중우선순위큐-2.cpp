#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// solution #2 priority_queue
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int count = 0; // 큐에 들어있는 숫자의 개수
    int size = operations.size();
    string first, second;
    for (int i=0; i<size; i++) {
        if (count == 0) { // 큐가 비었을 경우 maxHeap, minHeap 모두 초기화해서 비워줄 것
            while (!maxHeap.empty()) { maxHeap.pop(); }
            while (!minHeap.empty()) { minHeap.pop(); }
        }

        first = operations[i].substr(0, 1);
        second = operations[i].substr(2);
        if (first == "I") { // 큐에 주어진 숫자 삽입
            int num = stoi(second);
            maxHeap.push(num);
            minHeap.push(num);
            count++;
        }
        else { // first == "D"
            if (count == 0) { // 빈 큐에 데이터를 삭제하라는 연산이 주어질 경우 무시
                continue;
            }
            if (second == "1") { // 큐에서 최댓값 삭제
                maxHeap.pop();
                count--;
            }
            else { // second == "-1" 큐에서 최솟값 삭제
                minHeap.pop();
                count--;
            }
        }
    }

    // 큐가 비어있으면 [0,0] 
    int maxNum = 0;
    int minNum = 0;
    if (count != 0) {
        // 큐가 비어있지 않으면 [최댓값, 최솟값]
        maxNum = maxHeap.top();
        minNum = minHeap.top();
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