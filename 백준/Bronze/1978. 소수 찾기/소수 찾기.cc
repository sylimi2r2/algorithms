#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i=2; i*i<=num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int ans = 0;
    
    int N;
    cin >> N;

    for (int i=0; i<N; ++i) {
        int num;
        cin >> num;
        if (isPrime(num))
            ++ans;
    }

    cout << ans;
}