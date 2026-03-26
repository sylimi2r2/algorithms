#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int A[50];
    int B[50];
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i=0; i<N; i++)
        cin >> B[i];

    sort(A, A+N);
    sort(B, B+N);

    int sol = 0;
    for(int i=0; i<N; i++) {
        sol += A[i]*B[N-i-1];
    }

    cout << sol;
}