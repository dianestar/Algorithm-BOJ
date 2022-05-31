#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string getConverted(int n, int k) {
    string converted = "";
    while (n > 0) {
        converted += to_string(n%k);
        n /= k;
    }
    reverse(converted.begin(), converted.end());
    return converted;
}

bool isPrime(long long num) {
    if (num == 1) { return false; }
    for (int i=2; i<=(long long)sqrt(num); i++) {
        if (num % i == 0) { return false; }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string converted = getConverted(n, k);
    string temp = "";
    for (int i=0; i<converted.size(); i++) {
        if (converted[i] == '0') {
            if (temp != "" && isPrime(stoll(temp))) {
                answer++;
            }
            temp = "";
        }
        else {
            temp += converted[i];
        }
    }
    if (temp != "" && isPrime(stoll(temp))) {
        answer++;
    }
    
    return answer;
}

int main() {
    vector<int> n = {437674, 110011};
    vector<int> k = {3, 10};

    for (int i=0; i<n.size(); i++) {
        printf("%d\n", solution(n[i], k[i]));
    }
    
    return 0;
}