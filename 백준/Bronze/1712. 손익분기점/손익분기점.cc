#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    C -= B;
    if(C <= 0)
        cout << -1;
    else
        cout << (A/C+1);
}
