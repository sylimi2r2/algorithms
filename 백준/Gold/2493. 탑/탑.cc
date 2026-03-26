#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<pair<int, int>> s;
    int N, index = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;

        while(!s.empty()) {
            if(s.top().first > input) {
                cout << s.top().second << ' ';
                s.push({input, i+1});
                break;
            }
            else
                s.pop();
        }

        if(s.empty()) {
            cout << 0 << ' ';
            s.push({input, i+1});
        }
    }
}
