#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        stack<char> s;
        bool error = false;
        string input;
        cin >> input;

        for(int i=0; i<input.length(); i++) {
            char c = input[i];
            if(c == '(')
                s.push(c);
            else {
                if(!s.empty())
                    s.pop();
                else {
                    error = true;
                    break;
                }
            }
        }
        if(!s.empty())
            error = true;

        cout << (error ? "NO" : "YES") << '\n';
    }
}
