#include <iostream>

using namespace std;

bool buttons[10];

pair<bool, int> check(int channel) {
    if (channel == 0)
        return {buttons[0], 1};

    int cnt = 0;
    while (channel > 0) {
        ++cnt;
        if (!buttons[channel % 10])
            return {false, cnt};
        channel /= 10;
    }
    
    return {true, cnt};
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(buttons, buttons + 10, true);
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int num;
        cin >> num;
        buttons[num] = false;
    }

    int ans = abs(N - 100);
    int upper = max(2 * N, 100);
    for (int channel=0; channel<upper; ++channel) {
        pair<bool, int> info = check(channel);
        if (!info.first) continue;
        ans = min(ans, abs(N - channel) + info.second);
    }

    cout << ans;
}