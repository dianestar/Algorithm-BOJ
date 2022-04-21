#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        int sum = i;
        string s = to_string(i);
        for (int j=0; j<s.size(); j++) {
            sum += s[j] - '0';
        }
        if (sum == N) {
            printf("%d", i);
            return 0;
        }
    }

    printf("0");
    return 0;
}