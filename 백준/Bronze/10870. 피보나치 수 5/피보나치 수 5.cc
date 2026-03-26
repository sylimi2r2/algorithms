#include <iostream>
#include <algorithm>
using namespace std;

int fibo(int n) {
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return fibo(n-1) + fibo(n-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    cout << fibo(n);
}
