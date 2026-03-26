#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true) {
        stack<char> s;
        s.push('B');
        bool error = false;
        string input;
        getline(cin, input);

        if(input[0] == '.')
            break;

        for(int i=0; i<input.length(); i++) {
            char c = input[i];
            if(c == '(' || c == '[')
                s.push(c);
            else if(c == ')') {
                if(s.top() == '(')
                    s.pop();
                else {
                    error = true;
                    break;
                }
            }
            else if(c == ']') {
                if(s.top() == '[')
                    s.pop();
                else {
                    error = true;
                    break;
                }
            }
        }

        if(s.size() != 1)
            error = true;
        cout << (error ? "no\n" : "yes\n");
    }
}
