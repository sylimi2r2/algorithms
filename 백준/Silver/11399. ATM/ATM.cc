#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    vector<int> que;
    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        que.push_back(input);
    }

    sort(que.begin(), que.end());

    int sol = 0;
    for(int i=0; i<N; i++) {
        sol += que[i] * (N-i);
    }

    cout << sol;
}
