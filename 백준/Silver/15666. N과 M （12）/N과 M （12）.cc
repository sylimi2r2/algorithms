#include <iostream>
#include <set>
using namespace std;

int N, M;
int sol[8];
set<int> nums;

void dfs(int size, int index) {
    if(size == M) {
        for(int i=0; i<M; i++) {
            cout << sol[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int i = 0;
    for(int num : nums) {
        if(i == index) {
            sol[size] = num;
            dfs(size+1, index);
            dfs(size, index+1);
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        nums.insert(input);
    }

    dfs(0, 0);;
}