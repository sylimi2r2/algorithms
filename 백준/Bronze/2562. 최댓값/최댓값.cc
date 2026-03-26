#include <iostream>
using namespace std;

int main() {
    int arr[9];

    int n, max = 0, flag = 0;
    for(int i=0; i<9; ++i) {
        cin >> n;
        arr[i] = n;
        if(n > max){
            max = n;
            flag = i;
        }
    }
    cout << max << endl << flag+1;
    return 0;
}