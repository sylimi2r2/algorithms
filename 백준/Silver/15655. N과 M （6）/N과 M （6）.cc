#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[8] = {0,};
int inputs[8];

void dfs(int size, int index) {
    if(size == M) {
        for(int i=0; i<M; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    if(index == N)
        return;

    nums[size] = inputs[index];
    dfs(size+1, index+1);
    dfs(size, index+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> inputs[i];
    }
    sort(inputs, inputs+N);

    dfs(0, 0);
}
