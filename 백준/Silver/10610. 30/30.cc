#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sum = 0;
    string input;
    cin >> input;

    sort(input.rbegin(), input.rend());

    if(input.back() == '0') {
        for(char c : input) {
            sum += int(c);
        }

        if(sum%3 == 0)
            cout << input;
        else
            cout << -1;
    }
    else {
        cout << -1;
    }
}