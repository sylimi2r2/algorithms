#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    int denominator = 1, numerator = 1;

    for(int i=0; i<K; i++) {
        numerator *= N-i;
        denominator *= i+1;
    }

    cout << numerator/denominator;
}
