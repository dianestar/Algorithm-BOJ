#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &x, const string &y) {
    return x+y > y+x;
}

string solution(vector<int> numbers) {
    string answer = "";
    int N = numbers.size();
    
    // string으로 변환
    vector<string> strings;
    for (int i=0; i<N; i++) {
        strings.push_back(to_string(numbers[i]));
    }

    // 정렬 (cmp 함수 : 숫자 두 개씩 이어붙인 값 비교)
    sort(strings.begin(), strings.end(), cmp);

    // 정렬한 순서대로 숫자 이어붙여서 answer 값 구하기
    for (int i=0; i<N; i++) {
        answer += strings[i];
    }

    // 주어진 numbers에서 가장 큰 값이 0인 경우 answer = '0' 처리
    if (answer[0] == '0') {
        answer = '0';
    }

    return answer;
}

/* cf) permutation 활용 시 시간 초과 *
vector<string> candidates;

void permutation(vector<string> strings, int depth, int n) {
    if (depth == n) {
        string s = "";
        for (int i=0; i<n; i++) {
            s += strings[i];
        }
        candidates.push_back(s);
    }

    else {
        for (int i=depth; i<n; i++) {
            swap(strings[depth], strings[i]);
            permutation(strings, depth+1, n);
            swap(strings[depth], strings[i]);
        }
    }
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> strings;
    int N = numbers.size();
    for (int i=0; i<N; i++) {
        strings.push_back(to_string(numbers[i]));
    }
    permutation(strings, 0, N);
    sort(candidates.begin(), candidates.end(), greater<>());
    answer = candidates[0];

    return answer;
}
********************************/


int main() {
    vector<int> numbers1 = {6,10,2};
    cout << solution(numbers1) << endl;

    vector<int> numbers2 = {3,30,34,5,9};
    cout << solution(numbers2) << endl;

    return 0;
}