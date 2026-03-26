#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int lines[3];
    cin >> lines[0] >> lines[1] >> lines[2];
    sort(lines, lines+3);

    int sum = lines[0]+lines[1];

    if(lines[2] >= sum) {
        sum += sum-1;
    }
    else {
        sum += lines[2];
    }

    cout << sum;
}
