#include <iostream>
#include <vector>
using namespace std;

vector<int> lanCables;
int K, N;

bool check(long long len) {
    int count = 0;
    for(int i=0; i<K; i++) {
        count += lanCables[i] / len;
    }
    return (count >= N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;

    long long left = 1, right = 0;

    for(int i=0; i<K; i++) {
        int cable;
        cin >> cable;
        if(cable > right) right = cable;
        lanCables.push_back(cable);
    }

    int sol = 0;
    while(left <= right) {
        long long mid = (left+right)/2;
        if(check(mid)) {
            left = mid + 1;
            if(mid > sol) sol = mid;
        }
        else {
            right = mid - 1;
        }
    }
    cout << sol;
}
