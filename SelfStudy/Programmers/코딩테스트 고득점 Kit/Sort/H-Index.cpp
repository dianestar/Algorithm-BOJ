#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();

    // 인용 횟수 내림차순 정렬
    sort(citations.begin(), citations.end(), greater<>());

    int h = n; // h의 가능한 최댓값은 인용 횟수 배열의 크기
    int count = 0; // count는 h번 이상 인용된 논문의 개수
    while (h >= 0) {
        for (int i=0; i<n; i++) {
            while (citations[i] >= h) { i++; }
            count = i;
            break;
        }
        if (count >= h) { // h번 이상 인용된 논문이 h편 이상일 경우
            break;
        }
        h--;
    }
    answer = h;
    
    return answer;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    printf("%d", solution(citations));

    return 0;
}