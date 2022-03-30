#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int korean;
    int english;
    int math;
};

vector<Student> record;

bool cmp(const Student &a, const Student &b) {
    if (a.korean == b.korean) {
        if (a.english == b.english) {
            if (a.math == b.math) {
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string name;
    int korean, english, math;
    for (int i=0; i<N; i++) {
        cin >> name >> korean >> english >> math;
        record.push_back({name, korean, english, math});
    }

    sort(record.begin(), record.end(), cmp);

    for (int i=0; i<N; i++) {
        cout << record[i].name << "\n";
    }
    
    return 0; 
}