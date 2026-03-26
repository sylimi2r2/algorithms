#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, input;
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<>> right;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> input;
        left.push(input);

        if(left.size() > right.size()+1) {
            right.push(left.top());
            left.pop();
        }
        else {
            if(right.empty() || (left.top() > right.top())) {
                right.push(left.top());
                left.pop();
                left.push(right.top());
                right.pop();
            }
        }

        cout << left.top() << '\n';
    }
}
