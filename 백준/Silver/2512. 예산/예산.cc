#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec;
    int N;
    int sum = 0;
    cin >> N;

    int left = 0, right = 0;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
        sum += input;
        if(input > right) right = input;
    }

    int M;
    cin >> M;
    if(sum <= M) {
        cout << right;
    }
    else {
        int mid;
        int sol = 0;
        while(left <= right) {
            mid = (left+right)/2;
            sum = 0;
            for(int i=0; i<N; i++) {
                if(vec[i] < mid)
                    sum += vec[i];
                else
                    sum += mid;
            }
            if(sum <= M) {
                left = mid+1;
                if(mid > sol) sol = mid;
            }
            else {
                right = mid-1;
            }
        }
        cout << sol;
    }
}
