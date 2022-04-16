#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<vector<vector<int>>> digit = {
    {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}}, // 0
    {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, // 1
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}}, // 2
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}}, // 3
    {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1}}, // 4
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}}, // 5
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, // 6
    {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}}, // 7
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, // 8
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}} // 9
};
vector<vector<vector<int>>> clock(4, vector<vector<int>>(5, vector<int>(3, 0)));

/*
void printClock() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            for (int k=0; k<3; k++) {
                cout << clock[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    for (int j=0; j<5; j++) {
        for (int i=0; i<4; i++) {
            string block;
            cin >> block;

            for (int k=0; k<3; k++) {
                if (block[k] == '#') { clock[i][j][k] = 1; }
                else { clock[i][j][k] = 0; }
            }
        }
    }

    vector<int> answers;
    for (int i=0; i<4; i++) {
        for (int n=0; n<=9; n++) {
            bool flag = true;
            for (int j=0; j<5; j++) {
                for (int k=0; k<3; k++) {
                    if (clock[i][j][k] == 1 && digit[n][j][k] == 0) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) { break; }
            }
            if (flag) {
                answers.push_back(n);
                break;
            }
        }
    }

    cout << answers[0] << answers[1] << ":" << answers[2] << answers[3];
    
    return 0;
}