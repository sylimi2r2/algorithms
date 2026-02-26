#include <iostream>
#include <bitset>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        bitset<81> a, b;
        cin >> a >> b;

        bitset<81> sum;
        bool carry = false;
        for (int i=0; i<81; ++i) {
            int tmp = a[i] + b[i] + carry;
            sum[i] = (tmp & 1);
            carry = (tmp >= 2);
        }

        bool flag = false;
        for (int i=80; i>0; --i) {
            if (!flag) {
                if (!sum[i]) continue;
                flag = true;
            }
            cout << sum[i];
        }
        cout << sum[0] << '\n';
    }
}