#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while (n > 0) {
        // (현재까지 온 거리)*2 만큼 순간이동 -> 건전지 사용량이 들지 않는다
        if (n % 2 == 0) {
            n /= 2;
        }
        // K 칸을 앞으로 점프 -> K 만큼의 건전지 사용량이 든다
        else {    
            ans++;
            n--;
        }
    }

    return ans;
}

int main() {
    vector<int> N = {5,6,5000};
    
    for (int i=0; i<N.size(); i++) {
        printf("%d\n", solution(N[i]));
    }

    return 0;
}