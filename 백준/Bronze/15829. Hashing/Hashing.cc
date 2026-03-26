#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int M = 1234567891;
    int L;
    string s;
    cin >> L >> s;

    unsigned long hash = 0;
    for(int i=L-1; i>=0; i--) {
        hash = (hash*31 + (s[i]-96)) % M;
    }

    cout << hash;
}
