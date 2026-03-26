#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char c) {
    switch(c) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<char> s;
    string exp, converted = "";
    cin >> exp;

    for(int i=0; i<exp.length(); i++) {
        char c = exp[i];
        if(c>=65 && c<=90)
            converted += c;
        else {
            switch(c) {
                case '(': {
                    s.push('(');
                    break;
                }
                case ')': {
                    while(true) {
                        int top = s.top();
                        if(top == '(') {
                            s.pop();
                            break;
                        }
                        converted += top;
                        s.pop();
                    }
                    break;
                }
                default: {
                    int current = priority(c);
                    while(!s.empty()) {
                        int top = priority(s.top());
                        if(top>=current) {
                            converted += s.top();
                            s.pop();
                        }
                        else
                            break;
                    }
                    s.push(c);
                }
            }
        }
    }

    while(!s.empty()) {
        converted += s.top();
        s.pop();
    }

    cout << converted;
}
