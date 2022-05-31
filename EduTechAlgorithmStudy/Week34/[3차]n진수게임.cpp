#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> digit = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string getConvertedNum(int num, int n) {
    string remainders = "";
    
    while (num > 0) {
        remainders += digit[num % n];
        num /= n;
    }
    reverse(remainders.begin(), remainders.end());
    
    return remainders;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string totalList = "";
    totalList += '0';
    int totalCount = t * m;
    int num = 1;
    while (1) {
        if (totalList.size() >= totalCount) { break; }
        
        if (n == 10) { totalList += to_string(num); }
        else { totalList += getConvertedNum(num, n); }
        
        num++;
    }
    
    for (int i=p-1; i<totalCount; i+=m) {
        answer += totalList[i];
    }
    
    return answer;
}

int main() {
    vector<int> n = {2, 16, 16};
    vector<int> t = {4, 16, 16};
    vector<int> m = {2, 2, 2};
    vector<int> p = {1, 1, 2};

    for (int i=0; i<n.size(); i++) {
        cout << solution(n[i], t[i], m[i], p[i]) << "\n";
    }

    return 0;
}