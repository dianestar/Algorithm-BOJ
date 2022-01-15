#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        char arr[51];
        stack<int> s;
        int isVPS=1;
        scanf("%s", arr);

        for (int j=0; j<strlen(arr); j++) {
            if (arr[j]=='(') { s.push(1); }
            else {
                if (s.empty()) {
                    isVPS=0;
                    break;
                }
                else { s.pop(); }
            }
        }
        if (!s.empty()) { isVPS=0; }

        if (isVPS) { printf("YES\n"); }
        else { printf("NO\n"); }
    }

    return 0;
}