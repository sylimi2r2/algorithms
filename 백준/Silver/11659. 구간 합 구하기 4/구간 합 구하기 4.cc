#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> vec;
    int N, M;
    cin >> N >> M;

    int input;
    vec.push_back(0);
    for(int i=1; i<=N; i++) {
        cin >> input;
        vec.push_back(input+vec[i-1]);
    }

    while(M--) {
        int i, j;
        cin >> i >> j;
        cout << vec[j] - vec[i-1] << '\n';
    }
}
