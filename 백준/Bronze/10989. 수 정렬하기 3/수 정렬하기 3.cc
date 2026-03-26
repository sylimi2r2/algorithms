#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nums[10001] = {0,};
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        nums[num]++;
    }
    for(int i=1; i<10001; i++) {
        int count = nums[i];
        for(int j=0; j<count; j++) {
            cout << i << "\n";
        }
    }
}
