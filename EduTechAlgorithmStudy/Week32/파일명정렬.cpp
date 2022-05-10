#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct FileName {
    int index;
    string head;
    string number;
    string tail;
};

string toUpperCase(string str) {
    for (int i=0; i<str.size(); i++) {
        if (str[i] >= 97) { str[i] -= 32; }
    }
    return str;
}

bool cmp(const FileName &a, const FileName &b) {
    string headA = toUpperCase(a.head);
    string headB = toUpperCase(b.head);
    int numberA = stoi(a.number);
    int numberB = stoi(b.number);
    if (headA == headB) {
        if (numberA == numberB) {
            return a.index < b.index;
        }
        return numberA < numberB;
    }
    return headA < headB;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<FileName> fileList;
    
    int N = files.size();
    for (int i=0; i<N; i++) {
        string head, number, tail;
        string temp = "";
        for (int j=0; j<files[i].size(); j++) {
            if (files[i][j] - '0' >= 0 && files[i][j] - '0' < 10) {
                head = temp;
                temp = "";
                while (files[i][j] - '0' >= 0 && files[i][j] - '0' < 10) {
                    temp += files[i][j];
                    j++;
                }
                number = temp;
                tail = files[i].substr(j);
                fileList.push_back({i, head, number, tail});
                break;
            }
            temp += files[i][j];
        }
    }
    
    sort(fileList.begin(), fileList.end(), cmp);
    
    for (int i=0; i<N; i++) {
        string finalStr = fileList[i].head + fileList[i].number + fileList[i].tail;
        answer.push_back(finalStr);
    }
    
    return answer;
}
int main() {
    vector<string> files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    // vector<string> files = {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"};

    vector<string> answer = solution(files);
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}