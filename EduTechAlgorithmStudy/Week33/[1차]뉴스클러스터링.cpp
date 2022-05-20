#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>

using namespace std;

bool isAlphabet(char a) {
    if (a >= 65 && a <= 90) { return true; }
    return false;
}

vector<string> makeMultiSet(string str) { 
    for (int i=0; i<str.size(); i++) {
        // 다중집합 원소 사이를 비교할 때, 대문자와 소문자의 차이는 무시한다.
        str[i] = toupper(str[i]);
    }
    
    vector<string> strSet;
    for (int i=0; i<str.size()-1; i++) {
        // 영문자로 된 글자 쌍만 유효하고, 기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다. 
        if (!isAlphabet(str[i]) || !isAlphabet(str[i+1])) { continue; }
        
        // 입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다.
        strSet.push_back(str.substr(i, 2));
    }
    
    return strSet;
}

int solution(string str1, string str2) {
    vector<string> set1 = makeMultiSet(str1);
    vector<string> set2 = makeMultiSet(str2);
    
    // 두 집합 모두 공집합일 경우에는 J(A, B) = 1    
    // 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력
    if (set1.size() == 0 && set2.size() == 0) {
        return 65536;
    }

    unordered_map<string, int> um;    
    int gyo = 0;
    int hab = 0;
    for (int i=0; i<set1.size(); i++) {
        um[set1[i]]++;
        hab++;
    }
    
    for (int i=0; i<set2.size(); i++) {
        if (um[set2[i]]) {
            um[set2[i]]--;
            gyo++;
        }
        else {
            hab++;
        }
    }
    
    // 두 집합 A, B 사이의 자카드 유사도 J(A, B) = 두 집합의 교집합 크기 / 두 집합의 합집합 크기
    // 65536을 곱한 후에 소수점 아래를 버리고 정수부만 출력
    int answer = (double)(gyo) / hab * 65536;

    return answer;
}

int main() {
    vector<string> str1 = {"FRANCE", "handshake", "aa1+aa2", "E=M*C^2"};
    vector<string> str2 = {"french", "shake hands", "AAAA12", "e=m*c^2"};

    for (int i=0; i<str1.size(); i++) {
        printf("%d\n", solution(str1[i], str2[i]));
    }

    return 0;
}