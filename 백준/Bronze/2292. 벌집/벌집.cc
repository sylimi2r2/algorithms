#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int check = 1;
    int sum = 0;

    while(N > 0) {
        N -= check;
        sum++;
        check = 6*sum;
    }

    cout << sum;
}
