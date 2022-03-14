#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 입력
    int N, S;
    scanf("%d %d", &N, &S);

    vector<int> v;
    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        v.push_back(num);
    }

    int answer = 0;
    for (int i=1; i<=N; i++) { // 조합(부분수열)으로 선택할 원소 개수 1~N개
        vector<int> isSelected; // 선택할 원소 개수만큼 1 push
        for (int j=0; j<N-i; j++) { isSelected.push_back(0); }
        for (int j=0; j<i; j++) { isSelected.push_back(1); }
           
        // next_permutation을 활용한 조합(부분수열) 구하기
        do {
            int sum = 0;
            for (int j=0; j<N; j++) {
                if (isSelected[j]) { sum += v[j]; }
            }

            // cf) 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구할 것
            if (sum == S) { answer++; }
        } while (next_permutation(isSelected.begin(), isSelected.end()));
    }

    // 출력
    printf("%d", answer);

    return 0;
}