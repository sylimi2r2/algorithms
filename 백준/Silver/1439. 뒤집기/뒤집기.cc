#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int diff = 1;
    string input;
    cin >> input;

    for(int i=1; i<input.length(); i++) {
        if(input[i] != input[i-1])
            diff++;
    }

    cout << diff/2;
}