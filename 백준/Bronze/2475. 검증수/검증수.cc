#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 0;

    for(int i=0; i<5; i++) {
        int input; cin >> input;
        sum += input*input;
    }

    cout << sum%10;
}
