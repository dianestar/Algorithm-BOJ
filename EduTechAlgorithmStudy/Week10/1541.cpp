#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string arr;
    cin >> arr;

    string temp = "";
    bool minusMode = false;
    int sum = 0;
    int len = arr.size();
    for (int i=0; i<=len; i++) {
        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '\0') {
            if (!minusMode) {
                sum += stoi(temp);
                temp = "";

                if (arr[i] == '-') {
                    minusMode = true;
                }
            }
            else {
                sum -= stoi(temp);
                temp = "";
            }
        }
        else {
            temp += arr[i];
        }
    }

    printf("%d", sum);

    return 0;
}