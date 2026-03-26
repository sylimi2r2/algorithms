#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int nums[8] = {0,};
int picks[8] = {0,};

void dfs(int cnt, int prev) {
    if (cnt == M) {
        for (int i=0; i<M; ++i) {
            cout << picks[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i=prev; i<N; ++i) {
        picks[cnt] = nums[i];
        dfs(cnt + 1, i);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + N);

    dfs(0, 0);
}