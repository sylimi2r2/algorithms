#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    if(T%10)
        cout << "-1";
    else
        cout << T/300 << ' ' << (T%300)/60 << ' ' << ((T%300)%60)/10;
}
