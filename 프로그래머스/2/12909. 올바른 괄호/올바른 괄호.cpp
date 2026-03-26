#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> STACK;
    for(char c : s) {
        if(c == '(') {
            STACK.push('(');
        }
        else if(c == ')') {
            if(STACK.size()) {
                STACK.pop();
            }
            else return false;
        }
    }
    
    if(STACK.size())
        return false;
    
    return true;
}