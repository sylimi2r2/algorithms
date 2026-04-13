#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> STACK;
    
    for (char& c: s) {
        if (c == '(') {
            STACK.push(c);
        } else {
            if (STACK.empty())
                return false;
            
            if (STACK.top() == ')') {
                return false;
            } 
            
            STACK.pop();
        }
    }

    return STACK.empty();
}