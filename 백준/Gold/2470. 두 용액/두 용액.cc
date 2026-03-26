#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());

    int sol = 2000000000;
    int l, r;
    int left=0, right=N-1;
    while(left < right) {
        int cal = arr[left] + arr[right];

        if(abs(cal) < abs(sol)) {
            sol = cal;
            l = left;
            r = right;
        }
        if(cal == 0)
            break;
        else if(cal > 0)
            right--;
        else
            left++;
    }

    cout << arr[l] << ' ' << arr[r];
}
