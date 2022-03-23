#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> fibonacci(46);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i=2; i<=45; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    printf("%d", fibonacci[n]);
    
    return 0;
}