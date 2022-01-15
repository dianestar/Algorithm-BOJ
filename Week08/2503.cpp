#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int numList[1000];
    memset(numList, 1, sizeof(numList));
    for (int i=123; i<=987; i++) {
        string temp = to_string(i);
        if (temp[0] == temp[1] || temp[1] == temp[2] || temp[0] == temp[2]
            || temp[0] == '0' || temp[1] == '0' || temp[2] == '0' ) {
            numList[i] = 0;
        }
    }

    int num, S, B;
    for (int attempt=0; attempt<N; attempt++) {
        scanf("%d %d %d", &num, &S, &B);
        string guess = to_string(num);

        int s, b;
        for (int i=123; i<=987; i++) {
            if (numList[i]) {
                string candidate = to_string(i);
                s = 0;
                b = 0;
                for (int j=0; j<3; j++) {
                    for (int k=0; k<3; k++) {
                        if (j==k && guess[j] == candidate[k]) { s++; }
                        else if (j!=k && guess[j] == candidate[k]) { b++; }
                    }
                }
                if (s != S || b != B) { numList[i] = 0; }
            }
        }
    }

    int count=0;
    for (int i=123; i<=987; i++) {
        if (numList[i]) { count++; }
    }
    printf("%d", count);
    
    return 0;
}