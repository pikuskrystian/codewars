#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> precedence = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3}
};

bool isOperator(char c) {
    return precedence.count(c) > 0;
}

bool hasHigherPrecedence(char op1, char op2) {
    int precOp1 = precedence[op1];
    int precOp2 = precedence[op2];

    return (precOp1 > precOp2) || (precOp1 == precOp2 && op1 != '^');
}

std::string to_postfix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix;

    for (char c : infix) {
        if (std::isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && hasHigherPrecedence(operators.top(), c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}
