#include <iostream>
using namespace std;

int coins[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; i++)
        cin >> coins[i];

    int cnt = 0;
    while(K) {
        cnt += K/coins[N];
        K %= coins[N];
        N--;
    }

    cout << cnt;
}
