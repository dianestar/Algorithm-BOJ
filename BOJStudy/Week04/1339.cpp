#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int maxSum;
vector<string> words;
vector<char> candidates;
vector<char> map(256);

void getCandidates(string str) {
    int len = str.size();
    for (int i=0; i<len; i++) {
        candidates.push_back(str[i]);
    }
}

int calculate() {
    int sum = 0;
    for (int i=0; i<N; i++) {
        int converted = 0;
        int len = words[i].size();
        for (int j=0; j<len; j++) {
            converted = converted * 10 + map[words[i][j]];
        }
        sum += converted;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string str;
    for (int i=0; i<N; i++) {
        cin >> str;
        words.push_back(str);
        getCandidates(str);
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    
    vector<int> numbers;
    int count = candidates.size();
    for (int i=0; i<count; i++) {
        numbers.push_back(9-i);
    }

    do {
        for (int i=0; i<count; i++) {
            map[candidates[i]] = numbers[i];
        }
        int curSum = calculate();
        maxSum = max(maxSum, curSum);
    } while (prev_permutation(numbers.begin(), numbers.end()));

    printf("%d", maxSum);

    return 0;
}