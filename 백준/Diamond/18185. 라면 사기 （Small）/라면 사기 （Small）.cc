#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int A[10002] = {0,};
    int money = 0;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    int MIN;
    for(int i=2; i<=N+1; i++) {
        if(A[i-1]>A[i]) {
            MIN = min(A[i-2], A[i-1]-A[i]);
            money += 5*MIN;
            for(int j=1; j<3; j++)
                A[i-j] -= MIN;
        }
        MIN = min(A[i-2], min(A[i-1], A[i]));
        money += 7*MIN;
        for(int j=0; j<3; j++) {
            A[i-j] -= MIN;
        }
        MIN = min(A[i-2], A[i-1]);
        money += 5*MIN;
        for(int j=1; j<3; j++)
            A[i-j] -= MIN;
        money += 3*A[i-2];
        A[i-2] = 0;
    }

    cout << money;
}
