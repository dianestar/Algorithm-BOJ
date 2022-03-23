#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<char> result;
    stack<int> s;
    int num;
    int maxNum = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &num);

        if (s.empty() || num > s.top()) {
            for (int i=maxNum+1; i<=num; i++) {
                result.push_back('+');
                s.push(i);
            }
            maxNum = num;
        }

        if (num == s.top()) {
            result.push_back('-');
            s.pop();
        }

        else if (num < s.top()) {
            printf("NO");
            return 0;
        }
    }

    for (int i=0; i<result.size(); i++) {
        printf("%c\n", result[i]);
    }

    return 0;
}