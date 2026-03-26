#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int basket[N];
    for(int n=0; n<N; ++n) {
        basket[n] = 0;
    }
    int i, j, k;
    for(int n=0; n<M; ++n) {
        cin >> i >> j >> k;
        for(int m=i; m<=j; ++m) {
            basket[m-1] = k;
        }
    }
    for(int n=0; n<N; ++n) {
        cout << basket[n] << ' ';
    }
    return 0;
}