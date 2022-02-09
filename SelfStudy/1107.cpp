#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<bool> broken(10, false);

// 숫자 버튼을 직접 눌러서 채널 number로 이동할 수 있는지 체크
bool isValid(int number) {
    string s = to_string(number);
    int len = s.size();
    for (int i=0; i<len; i++) {
        if (broken[s[i]-'0']) {
            return false; // invalid한 경우 return false
        }
    }
    return true; // valid한 경우 return true
}

int main() {
    int N;
    scanf("%d", &N);

    int M;
    scanf("%d", &M);
    int num;
    for (int i=0; i<M; i++) {
        scanf("%d", &num);
        broken[num] = true;
    }

    int absCount = abs(100-N); // +1 또는 -1 버튼을 눌러서 채널 N으로 이동할 경우 버튼을 누르는 횟수  
    int count = to_string(N).size();
    if (isValid(N) && count < absCount){ // A) 채널 N에 해당하는 숫자 버튼을 직접 눌러서 이동하는 경우가 최소값
        printf("%d", count);
    }

    else {
        int i = 1; // +1 또는 -1 버튼을 누르는 횟수
        while (true) { 
            int smallerNum = N-i;
            int biggerNum = N+i;

            int smallerCount = i + to_string(smallerNum).size();
            int biggerCount = i + to_string(biggerNum).size();

            if (smallerCount >= absCount && biggerCount >= absCount) { // B) +1 또는 -1 버튼을 눌러서 이동하는 경우가 최소값
                printf("%d", absCount);
                break;
            }

            if (smallerNum >= 0 && isValid(smallerNum) && smallerCount < absCount) { // C) 채널 N보다 i만큼 작은 수의 채널로 이동한 후 i번만큼 +1 버튼을 눌러서 이동하는 경우가 최소값
                printf("%d", smallerCount);
                break;
            }

            if (isValid(biggerNum) && biggerCount < absCount) { // D) 채널 N보다 i만큼 큰 수의 채널로 이동한 후 i번만큼 -1 버튼을 눌러서 이동하는 경우가 최소값
                printf("%d", biggerCount);
                break;
            }

            i++;
        }
    }

    return 0;
}