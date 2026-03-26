#include <iostream>
using namespace std;

#define PI 3.141592

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int d1, d2;
    cout << fixed;
    cout.precision(6);
    cin >> d1 >> d2;
    cout << (2*d1 + 2*PI*d2);
}