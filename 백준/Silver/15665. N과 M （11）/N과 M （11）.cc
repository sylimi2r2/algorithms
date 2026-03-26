#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[8];
int sol[8];

void dfs(int size) {
    if(size==M) {
        for(int i=0; i<M; i++)
            cout << sol[i] << ' ';
        cout << '\n';
        return;
    }

    int previous = -1;
    for(int i=0; i<N; i++) {
        if(nums[i] != previous) {
            sol[size] = nums[i];
            previous = nums[i];
            dfs(size+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> nums[i];

    sort(nums, nums+N);

    dfs(0);
}
