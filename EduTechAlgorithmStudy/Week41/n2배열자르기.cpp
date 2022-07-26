#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i=left; i<=right; i++) {
        int row = i % n;
        int col = i / n;
        answer.push_back(max(row, col) + 1);
    }
    
    return answer;
}

int main() {
    vector<int> n = {3, 4};
    vector<long long> left = {2, 7};
    vector<long long> right = {5, 14};

    for (int i=0; i<n.size(); i++) {
        vector<int> answer = solution(n[i], left[i], right[i]);
        for (int j=0; j<answer.size(); j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }

    return 0;
}