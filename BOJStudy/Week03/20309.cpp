#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int num;
    for (int i=1; i<=N; i++) {
        scanf("%d", &num);
        if (i%2 == 0 && num%2 == 1) {
            printf("NO");
            return 0;
        }
        else if (i%2 == 1 && num%2 ==0) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}