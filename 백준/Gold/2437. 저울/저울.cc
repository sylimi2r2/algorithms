#include <iostream>
#include <algorithm>
using namespace std;

int N;
int weights[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> weights[i];

    sort(weights, weights+N);

    int sol = 0;
    for(int i=0; i<N; i++) {
        if(sol+1 >= weights[i]) {
            sol += weights[i];
        }
        else {
            break;
        }
    }

    cout << sol+1;
}
