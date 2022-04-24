#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int calculate(string str) {
    int result = 0;
    char flag = '+';
    string temp = "";
    for (int i=0; i<str.size(); i++) {
        if (str[i] == ' ') { continue; }
        else if (str[i] == '+' || str[i] == '-') {
            if (flag == '+') { result += stoi(temp); }
            else if (flag == '-') { result -= stoi(temp); }
            temp = "";
            flag = str[i];
        }
        else {
            temp += str[i];
        }
    }
    if (flag == '+') { result += stoi(temp); }
    else if (flag == '-') { result -= stoi(temp); }

    return result ;
}

void makeStr(int len, int num, string str) {
    if (str.size() == (len*2-1)) {
        if (calculate(str) == 0) {
            cout << str << "\n";
        }
        return;
    }

    makeStr(len, num+1, str+' '+to_string(num+1));
    makeStr(len, num+1, str+'+'+to_string(num+1));
    makeStr(len, num+1, str+'-'+to_string(num+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> testcase(10);
    for (int i=0; i<N; i++) {
        cin >> testcase[i];
    }

    for (int i=0; i<N; i++) {
        makeStr(testcase[i], 1, "1");
        cout << "\n";
    }

    return 0;
}