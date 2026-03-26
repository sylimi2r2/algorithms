#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> fibo(41);
    fibo[0] = {1, 0};
    fibo[1] = {0, 1};
    for(int i=2; i<=40; i++) {
        fibo[i] = {fibo[i-1][0]+fibo[i-2][0], fibo[i-1][1]+fibo[i-2][1]};
    }
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> N;
        cout << fibo[N][0] << ' ' << fibo[N][1] << '\n';
    }
}
