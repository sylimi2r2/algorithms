#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ropes[100000];
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> ropes[i];

    sort(ropes, ropes+N);

    int sol = 0;
    for(int i=0; i<N; i++) {
        sol = max(sol, ropes[i]*(N-i));
    }

    cout << sol;
}