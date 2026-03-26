#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BSearch(vector<int> &v, int target) {
    int length = v.size();
    int left = 0, right = length-1;
    int mid;

    while(left <= right) {
        mid = (left+right)/2;

        if(v[mid] == target) {
            return 1;
        }
        else {
            if(v[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        cout << BSearch(vec, input) << ' ';
    }
}
