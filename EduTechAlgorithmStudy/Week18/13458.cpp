#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N; //시험장의 개수 (N)
    scanf("%d", &N); 

    vector<int> applicants; //각 시험장에 있는 응시자의 수 (Ai)
    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        applicants.push_back(num);
    }

    int main, sub; //main(총감독관) vs sub(부감독관)이 한 시험장에서 감시할 수 있는 응시자의 수 (B, C)
    scanf("%d %d", &main, &sub);

    /* N:1,000,000  Ai:1,000,000  B:1  C:1 일 경우
       answer:1,000,000,000,000 (1조, int 범위 초과) */
    long long answer = 0; 
    for (int i=0; i<N; i++) {
        answer++;
        applicants[i] -= main;

        if (applicants[i] > 0) {
            answer += ceil((double)applicants[i]/sub);
        }
    }

    printf("%lld", answer);

    return 0;
}