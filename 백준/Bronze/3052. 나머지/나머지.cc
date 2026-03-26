#include <iostream>
using namespace std;

int main() {
    int arr[42] = {0,};
    int n, cnt=0;
    for(int i=0; i<10; i++) {
        cin >> n;
        arr[n%42] += 1;
        if(arr[n%42]==1) cnt+=1;
    }
    cout << cnt;
    return 0;
}