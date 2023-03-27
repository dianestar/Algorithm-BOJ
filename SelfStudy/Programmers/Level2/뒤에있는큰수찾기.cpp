#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // 뒷 큰수: 자신보다 뒤에 있는 숫자 중에서 자신보다 크면서 가장 가까이 있는 수
    // 뒷 큰수가 존재하지 않을 경우 -1
    
    int len = numbers.size();
    vector<int> answer(len);
    
    stack<int> s;
    s.push(numbers[len - 1]);
    answer[len - 1] = -1;
    
    int startIdx = len - 2;
    for (int i=startIdx; i>=0; i--) {
        while (!s.empty() && s.top() <= numbers[i]) s.pop();
        
        if (s.empty()) answer[i] = -1;
        else answer[i] = s.top();
        
        s.push(numbers[i]);
    }
    
    return answer;
}

int main() {
    vector<vector<int>> numbers = {
        {2, 3, 3, 5},
        {9, 1, 5, 3, 6, 2}
    };

    for (int i=0; i<numbers.size(); i++) {
        vector<int> answer = solution(numbers[i]);
        for (int j=0; j<answer.size(); j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }

    return 0;
}