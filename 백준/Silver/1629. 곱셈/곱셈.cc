#include <iostream>
using namespace std;

int A, B, C;

long long sol(long long b) {
    if(b == 1)
        return A%C;

    long long divide = sol(b/2)%C;
    if(b%2 == 0)
        return divide*divide%C;

    else
        return (divide*divide%C*A%C)%C;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B >> C;

    cout << sol(B);
}
