#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> stack;

    int N; cin >> N;
    string cmd;
    for(int i=0; i<N; i++) {
        cin >> cmd;
        if(cmd == "push") {
            int X; cin >> X;
            stack.push_back(X);
        }
        else if(cmd == "pop") {
            if(stack.size()) {
                cout << stack[stack.size()-1] << "\n";
                stack.erase(stack.end()-1);
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if(cmd == "size") {
            cout << stack.size() << "\n";
        }
        else if(cmd == "empty") {
            cout << (stack.size() ? 0 : 1) << "\n";
        }
        else {
            cout << (stack.size() ? stack[stack.size()-1] : -1) << "\n";
        }
    }

}
