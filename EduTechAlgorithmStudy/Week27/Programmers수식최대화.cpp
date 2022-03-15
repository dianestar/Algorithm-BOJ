#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> priority = {'*', '+', '-'}; 
long long answer = 0;

void calculate(vector<long long> operands, vector<char> operators) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<operators.size(); j++) {
            if (operators[j] == priority[i]) {
                if (operators[j] == '+') { operands[j] += operands[j+1]; }
                else if (operators[j] == '-') { operands[j] -= operands[j+1]; }
                else if (operators[j] == '*') { operands[j] *= operands[j+1]; }
                operands.erase(operands.begin() + (j+1));
                operators.erase(operators.begin() + j);
                j--;
            }
        }
    }
    answer = max(answer, abs(operands[0]));
}

long long solution(string expression) {
    vector<long long> operands;
    vector<char> operators;
    
    string number = "";
    for (int i=0; i<expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            operands.push_back(stoi(number));
            number = "";
            operators.push_back(expression[i]);
        }
        else {
            number += expression[i];
        }
    }
    operands.push_back(stoi(number));
    
    do {
        calculate(operands, operators);
    } while (next_permutation(priority.begin(), priority.end()));
    
    return answer;
}

int main() {
    // string expression1 = "100-200*300-500+20";
    string expression2 = "50*6-3*2";

    // printf("%d\n", solution(expression1));
    printf("%d\n", solution(expression2));

    return 0;
}