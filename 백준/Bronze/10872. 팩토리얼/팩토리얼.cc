#include <iostream>
using namespace std;

int factorial(int n) {
    if(n==0 || n==1)
        return 1;
    return n*factorial(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cout << factorial(N);
}
