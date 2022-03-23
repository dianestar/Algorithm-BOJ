#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int out, in;
    int curCount = 0;
    int maxCount = 0;
    for (int i=0; i<10; i++) {
        scanf("%d %d", &out, &in);
        curCount -= out;
        curCount += in;
        maxCount = max(maxCount, curCount);
    }

    printf("%d", maxCount);
    
    return 0;
}