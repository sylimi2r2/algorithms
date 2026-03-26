#include <iostream>
#define MAX 1000000000
using namespace std;


int main() {
    int N; cin >> N;
    int n = 0;
    for(int i=666; i<MAX; i++) {
        int count = 0;
        int num = i;
        while(num) {
            if(num%10 == 6) {
                count++;
            }
            else {
                count = 0;
            }
            if(count == 3) {
                n++;
                break;
            }
            num /= 10;
        }
        if(n == N) {
            cout << i;
            break;
        }
    }
}
