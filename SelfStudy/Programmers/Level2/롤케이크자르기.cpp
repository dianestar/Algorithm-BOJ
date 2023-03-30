#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// countA와 countB는 철수와 동생이 각각 맛볼 수 있는 토핑의 가짓수
// selectedA와 selectedB의 key는 토핑 번호, value는 해당 번호의 토핑 개수
int answer, countA, countB;
unordered_map<int, int> selectedA; 
unordered_map<int, int> selectedB;

int solution(vector<int> topping) {
    // 처음에는 첫 번째 토핑과 두 번째 토핑 사이를 자르는 것으로 가정
    countA++;
    selectedA[topping[0]] = 1;
    for (int i=1; i<topping.size(); i++) {
        if (selectedB[topping[i]] == 0) countB++;
        selectedB[topping[i]]++;
    }
    if (countA == countB) answer++;
    
    // 자르는 위치를 오른쪽으로 하나씩 이동
    for (int i=1; i<topping.size(); i++) {
        if (selectedA[topping[i]] == 0) countA++;
        selectedA[topping[i]]++;

        if (selectedB[topping[i]] == 1) countB--;
        selectedB[topping[i]]--;

        if (countA == countB) answer++;
    }
    
    return answer;
}

int main() {
    // vector<int> topping = {1, 2, 1, 3, 1, 4, 1, 2};
    vector<int> topping = {1, 2, 3, 1, 4};

    printf("%d", solution(topping));


    return 0;
}