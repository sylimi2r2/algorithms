#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    int K; cin >> K;

    int input;
    int sum = 0;
    for(int i=0; i<K; i++) {
        cin >> input;
        if(input != 0) {
            sum += input;
            s.push(input);
        }
        else {
            sum -= s.top();
            s.pop();
        }
    }

    cout << sum;
}
