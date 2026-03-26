#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    if(N%5==0) {
        cout << N/5;
    }
    else {
        int remain;
        int fives = N/5;
        while(fives) {
            remain = N - fives*5;
            if(remain%3 == 0) {
                cout << fives + remain/3;
                break;
            }
            fives--;
        }
        if(fives == 0) {
            if(N%3 == 0) cout << N/3;
            else cout << -1;
        }
    }
}
