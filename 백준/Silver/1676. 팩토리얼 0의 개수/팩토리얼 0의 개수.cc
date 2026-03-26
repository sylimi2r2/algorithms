#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int fives = 0, twos = 0;
    for(int i=2; i<=N; i++) {
        int num = i;
        while(num > 1){
            if(num%5 == 0) {
                fives++;
                num /= 5;
            }
            else {
                break;
            }
        }
    }
    cout << fives;
}
