#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int nums[8] = {0,};
int picks[8] = {0,};
int picked[8];

void dfs(int cnt) {
    if (cnt == M) {
        for (int i=0; i<M; ++i) {
            cout << picks[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i=0; i<N; ++i) {
        if (!picked[i]) {
            picked[i] = true;
            picks[cnt] = nums[i];
            dfs(cnt + 1);
            picked[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fill(picked, picked + 8, false);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    dfs(0);
}