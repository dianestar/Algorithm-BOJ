#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

string toUpper(string str) {
    for (int i=0; i<str.size(); i++) {
        if (str[i] >= 97) { str[i] -= 32; }
    }
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for (int i=0; i<cities.size(); i++) {
        cities[i] = toUpper(cities[i]);
    }

    deque<string> cache;
    for (int i=0; i<cities.size(); i++) {
        auto iter = find(cache.begin(), cache.end(), cities[i]);
        if (iter != cache.end()) {
            answer += 1;
            cache.erase(iter);
            cache.push_back(cities[i]);
        }
        else { 
            answer+= 5;
            if (!cache.empty() && cache.size() >= cacheSize) { cache.pop_front(); }
            if (cacheSize != 0) { cache.push_back(cities[i]); }
        }
    }
    
    return answer;
}

int main() {
    vector<int> cacheSize = {3, 3, 2, 5, 2, 0};
    vector<vector<string>> cities = {
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"},
        {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"},
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"},
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"},
        {"Jeju", "Pangyo", "NewYork", "newyork"},
        {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"},
    };

    for (int i=0; i<cacheSize.size(); i++) {
        printf("%d\n", solution(cacheSize[i], cities[i]));
    }

    return 0;
}