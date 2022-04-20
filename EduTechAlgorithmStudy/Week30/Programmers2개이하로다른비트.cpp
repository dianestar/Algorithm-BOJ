#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string getReversedBinary(long long decimal) {
    string binary = "";
    
    while (decimal > 0) {
        binary += to_string(decimal % 2);
        decimal /= 2;
    }

    return binary;
}

long long getDecimal(string binary) {
    long long decimal = 0;
    int power = 0;
    int len = binary.size();
    
    for (int i=0; i<len; i++) {
        if (binary[i] != '0') {
            decimal += pow(2, power);
        }
        power++;
    }
    
    return decimal;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i] % 2 == 0) { // 짝수일 경우
            answer.push_back(numbers[i] + 1);
        }
        else { // 홀수일 경우
            string binary = getReversedBinary(numbers[i]);
            int len = binary.size();
            if (binary.find('0') == string::npos) {
                binary[len-1] = '0';
                binary.push_back('1');
            }
            else {
                for (int i=0; i<len; i++) {
                    if (binary[i] == '0') {
                        binary[i] = '1';
                        if (i > 0) { binary[i-1] = '0'; }
                        break;
                    }
                }
            }
            answer.push_back(getDecimal(binary));
        }
    }
    
    return answer;
}

/* 시간초과
string getbinary(long long number) {
    string binary = "";
    while (number > 0) {
        binary += to_string(number % 2);
        number /= 2;
    }
    return binary;
}

bool checkValid(long long a, long long b) {
    string strA = getbinary(a);
    string strB = getbinary(b);
    
    int lenDiff = abs((int)(strA.size() - strB.size()));
    if (lenDiff > 2) { return false; }
    
    int minLen = min(strA.size(), strB.size());
    int diffCount = 0;
    for (int i=0; i<minLen; i++) {
        if (strA[i] != strB[i]) { diffCount++; }
    }
    
    if ((diffCount + lenDiff) > 2) { return false; }
    
    return true;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i=0; i<numbers.size(); i++) {
        long long number = numbers[i];
        long long candidate = number + 1;
        while (!checkValid(number, candidate)) {
            candidate++;
        }
        answer.push_back(candidate);
    }
    
    return answer;
}
*/

int main() {
    vector<long long> numbers = {2, 7};

    vector<long long> answer = solution(numbers);
    for (int i=0; i<answer.size(); i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}