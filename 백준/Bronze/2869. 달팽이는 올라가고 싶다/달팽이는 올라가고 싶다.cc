#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, V; cin >> A >> B >> V;
    int x = V-A;
    int y = A-B;
    cout << x/y + (x%y != 0) + 1;
}
