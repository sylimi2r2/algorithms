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

    int sol = 0;
    for(int i=0; i<N; i++) {
        int left = 0;
        int right = N-1;
        while(left < right) {
            if(left == i) {
                left++;
                continue;
            }
            if(right == i) {
                right--;
                continue;
            }
            int cal = arr[left] + arr[right];
            if(cal == arr[i]) {
                sol++;
                break;
            }
            else if(cal > arr[i])
                right--;
            else
                left++;
        }
    }

    cout << sol;
}
