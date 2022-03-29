#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 2 * 10e9 * 2 * 10e5; // 최악의 상황 a=10e9, b=10e9, w=1, t=10e5
    
    int N = t.size();
    long long start = 0;
    long long end = answer; 
    while (start <= end) {
        long long mid = (start + end) / 2;
        
        long long arrivedG = 0;
        long long arrivedS = 0;
        long long arrivedGS = 0;
        
        for (int i=0; i<N; i++) {
            long long count = mid / (t[i] * 2);
            if (mid % (t[i] * 2) >= t[i]) { count++; }
            long long maxW = w[i] * count;
            
            arrivedG += min(maxW, (long long)g[i]);
            arrivedS += min(maxW, (long long)s[i]);
            arrivedGS += min(maxW, (long long)(g[i] + s[i]));
        }
        
        if (arrivedG >= a && arrivedS >= b && arrivedGS >= (a+b)) {
            if (mid < answer) { answer = mid; }
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    return answer;
}

int main() {
    /*
    int a = 10;
    int b = 10;
    vector<int> g = {100};
    vector<int> s = {100};
    vector<int> w = {7};
    vector<int> t = {10};
    */

    int a = 90;
    int b = 500;
    vector<int> g = {70, 70, 0};
    vector<int> s = {0, 0, 500};
    vector<int> w = {100, 100, 2};
    vector<int> t = {4, 8, 1};

    printf("%lld", solution(a, b, g, s, w, t));

    return 0;
}