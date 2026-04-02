#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int input;
    int ans = -100'000'001;
    int unDel = -100'000'001;
    int del = -100'000'001;
    for (int i=1; i<=n; ++i) {
        cin >> input;

        int nextUnDel = max(unDel + input, input);
        int nextDel = max(unDel, del + input);

        unDel = nextUnDel;
        del = nextDel;

        ans = max(ans, max(unDel, del));
    }

    cout << ans;
}