#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getBinaryCount(int decimal) {
    int count = 0;

    while (decimal > 0) {
        if (decimal % 2 == 1) { count++; }
        decimal /= 2;
    }
    
    return count;
}

int solution(int n) {
    int countN = getBinaryCount(n);
    
    while (1) {
        n++;
        int countNext = getBinaryCount(n);
        if (countN == countNext) { break; }
    }

    return n;
}
int main() {
    vector<int> n = {78, 15};

    for (int i=0; i<n.size(); i++) {
        printf("%d\n", solution(n[i]));
    }
    return 0;
}