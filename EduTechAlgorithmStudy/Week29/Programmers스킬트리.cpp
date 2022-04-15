#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    
    unordered_map<char, int> priorities;
    for (int i=0; i<skill.size(); i++) {
        priorities[skill[i]] = i+1;
    }
    
    for (int i=0; i<skill_trees.size(); i++) {
        vector<int> priorities_tree;
        
        for (int j=0; j<skill_trees[i].size(); j++) {
            int priority = priorities[skill_trees[i][j]];
            if (priority != 0) {
                priorities_tree.push_back(priority);
            }
        }
        
        for (int j=0; j<priorities_tree.size(); j++) {
            if (priorities_tree[j] != j+1) {
                answer--;
                break;
            }
        }
    }
    
    return answer;
}

int main() {
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

    printf("%d", solution(skill, skill_trees));

    return 0;
}