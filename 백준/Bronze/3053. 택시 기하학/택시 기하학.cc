#include <iostream>
using namespace std;

#define PI 3.14159265358979

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R;
    cin >> R;

    cout.precision(6);
    cout << fixed;
    cout << R*R*PI << '\n';
    cout << (double)2*R*R;
}
