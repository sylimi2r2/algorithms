#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int length[3];
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> length[0] >> length[1] >> length[2];
        sort(length, length+3);

        cout << "Scenario #" << i << ":\n";
        if(length[0]*length[0]+length[1]*length[1]==length[2]*length[2])
            cout << "yes\n";
        else
            cout << "no\n";

        cout << '\n';
    }
}