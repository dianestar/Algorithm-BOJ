#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    
    string characters = "ACFJMNRT";
    do {
        bool flag = true;
        for (int i=0; i<n; i++) {
            int idxA = characters.find(data[i][0]);
            int idxB = characters.find(data[i][2]);
            int distance = abs(idxA - idxB) - 1;  
            char sign = data[i][3];
            int number = data[i][4] - '0';
            if (sign == '=' && distance != number) {
                flag = false;
                break;
            }
            else if (sign == '<' && distance >= number) {
                flag = false;
                break;
            }
            else if (sign == '>' && distance <= number) {
                flag = false;
                break;          
            }
        }
        if (flag) { answer++; }
    } while (next_permutation(characters.begin(), characters.end()));
    
    return answer;
}

int main() {
    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};

    printf("%d", solution(n, data));

    return 0;
}