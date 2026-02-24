#include <iostream>
using namespace std;

int gcd(int num1, int num2) {
    if(num2 == 0) return num1;
    else return gcd(num2, num1 % num2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int GCD = gcd(a, b);
    cout << GCD << "\n" << a*b/GCD;
}
