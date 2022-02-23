#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num == 0 || num == 1) { return false; }
    
    for (int i=2; i<=(int)sqrt(num); i++) {
        if (num%i == 0) { return false; }
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end()); // numbers 오름차순 정렬
    
    vector<int> candidates; // 만들 수 있는 모든 숫자를 담는 벡터
    do { // numbers의 순열 구하기
        string number = "";
        for (int i=0; i<numbers.size(); i++) {
            number += numbers[i]; // 1자리 숫자부터 numbers.size()자리 숫자까지 모두 생성
            candidates.push_back(stoi(number)); // string -> integer 변환하여 candidates 벡터에 추가
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    // candidates 중에서 중복되는 숫자 제거 
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    
    // candidates 숫자들에 대해 소수인지 체크
    for (int i=0; i<candidates.size(); i++) {
        if (isPrime(candidates[i])) {
            answer++;
        }
    }
    
    return answer;
}

int main() {
    string numbers1 = "17";
    string numbers2 = "011";

    printf("%d %d", solution(numbers1), solution(numbers2));

    return 0;
}