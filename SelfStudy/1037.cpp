#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> realDivisor;
    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        realDivisor.push_back(num);
    }

    int maxDivisor = *max_element(realDivisor.begin(), realDivisor.end());
    int minDivisor = *min_element(realDivisor.begin(), realDivisor.end());
    
    int answer = maxDivisor * minDivisor;
    printf("%d", answer);

    return 0;
}