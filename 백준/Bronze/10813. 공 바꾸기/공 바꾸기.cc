#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int basket[N];
    for(int n=0; n<N; ++n) {
        basket[n] = n+1;
    }
    int i, j, temp;
    for(int n=0; n<M; ++n) {
        cin >> i >> j;
        temp = basket[i-1];
        basket[i-1] = basket[j-1];
        basket[j-1] = temp;
    }
    for(int n=0; n<N; ++n) {
        cout << basket[n] << ' ';
    }
    return 0;
}