#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string combination[101][101];

string getStrSum(string a, string b) {
    long long sum = 0;
    string str = "";
    
    while (a.size() || b.size() || sum) {
        // 두 string a와 b를 각각 가장 뒷자리부터 정수로 변환하여 더함
        if (a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }

        // 더한 값이 두 자리일 경우
        // i) 일의 자리는 str에 더해줌
        str.push_back((sum % 10) + '0');
        // ii) 십의 자리는 다음 자리 연산에 활용
        sum /= 10;
    }

    // 가장 뒷자리부터 연산하여 str에 push 하였으므로
    // str 값을 reverse하여 return
    reverse(str.begin(), str.end());
    return str;
}

string getCombination(int n, int m) {
    if (n == m || m == 0) { return "1"; }

    string &value = combination[n][m];
    // memoization 해둔 값이 있을 경우 return
    if (value != "") { return value; }
    // 없을 경우 nCm = n-1Cm-1 + n-1Cm 공식 활용하여 조합 구하기
    // 계산 과정에서 long long 범위를 넘어가는 값이 나올 수 있으므로 string끼리의 덧셈 연산을 getStrSum 함수로 구현
    value = getStrSum(getCombination(n-1, m-1), getCombination(n-1, m));
    return value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    cout << getCombination(n, m);

    return 0;
}