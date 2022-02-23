#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution_using_forLoop(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N, 0);
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            answer[i]++;
            if (prices[i] > prices[j]) { break; }
        }
    }
    return answer;
}

vector<int> solution_using_stack(vector<int> prices) {
    int N = prices.size();
    vector<int> answer(N);
    stack<int> timeStack;

    for (int i=0; i<N; i++) {
        while (!timeStack.empty() && prices[i] < prices[timeStack.top()]) { // 가격이 떨어진 경우
            answer[timeStack.top()] = i-timeStack.top(); // 떨어지지 않은 기간 계산 (현재 시점 - 해당 시점)
            timeStack.pop(); // 해당 시점 pop
        }
        timeStack.push(i); // 현재 시점 push
    }

    while(!timeStack.empty()) { // 끝까지 가격이 떨어지지 않은 나머지 경우들 처리
        answer[timeStack.top()] = (N-1) - timeStack.top(); // 떨어지지 않은 기간 계산 (종료 시점 - 해당 시점)
        timeStack.pop(); // 처리 완료된 해당 시점 pop
    }

    return answer;
}

int main() {
    vector<int> prices = { 1, 2, 3, 2, 3 };
    vector<int> answer1 = solution_using_forLoop(prices);
    vector<int> answer2 = solution_using_forLoop(prices);
    for (int i=0; i<answer1.size(); i++) {
        printf("%d %d\n", answer1[i], answer2[i]);
    }

    return 0;
}