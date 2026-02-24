#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 1'000'000;
bool isPrime[MAXN + 1];
vector<int> primes;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(isPrime, isPrime + MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i=2; i*i<=MAXN; ++i) {
        if (!isPrime[i]) continue;
        for (int j=i*i; j<=MAXN; j+=i) {
            isPrime[j] = false;
        }
    }

    for (int i=2; i<=MAXN; ++i) {
        if (isPrime[i])
            primes.push_back(i);
    }

    int n;
    while (true) {
        bool found = false;
        cin >> n;
        if (n == 0)
            break;
        for (int i=1; i<primes.size(); ++i) {
            int prime = primes[i];
            if (prime > n / 2) {
                break;
            }
            if (isPrime[n - prime]) {
                cout << n << " = " << prime << " + " << n - prime << '\n';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}