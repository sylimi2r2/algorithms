#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<char> s;
    int sol = 0, tmp = 1;
    string input;
    cin >> input;

    for(int i=0; i<input.length(); i++) {
        char c = input[i];

        switch(c) {
            case '(':
                tmp *= 2;
                s.push('(');
                break;
            case '[':
                tmp *= 3;
                s.push('[');
                break;
            case ')':
                if(s.empty() || s.top()=='[') {
                    cout << 0;
                    exit(0);
                }
                if(input[i-1]=='(')
                    sol += tmp;

                tmp /= 2;
                s.pop();
                break;
            case ']':
                if(s.empty() || s.top()=='(') {
                    cout << 0;
                    exit(0);
                }
                if(input[i-1]=='[')
                    sol += tmp;

                tmp /= 3;
                s.pop();
                break;
        }
    }

    if(!s.empty())
        sol = 0;

    cout << sol;
}
