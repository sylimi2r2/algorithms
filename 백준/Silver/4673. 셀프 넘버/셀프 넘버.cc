#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    bool nums[10001] = {0,};

    for(int i=1; i<=10000; i++) {
        int num = i + (i % 10) + (i / 10 % 10) + (i / 100 % 10) + (i / 1000 % 10) + (i / 10000 % 10);
        if (num <= 10000) {
            nums[num] = true;
        }
    }

    for(int i=1; i<=10000; i++) {
        if(!nums[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}