#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    int MIN = 1'000'000'001;
    int MAX = 0;
    for (int i=0; i<N; ++i) {
        int tmp;
        cin >> tmp;
        MIN = min(MIN, tmp);
        MAX = max(MAX, tmp);
    }

    cout << 2 * MAX - 2 * MIN;
}