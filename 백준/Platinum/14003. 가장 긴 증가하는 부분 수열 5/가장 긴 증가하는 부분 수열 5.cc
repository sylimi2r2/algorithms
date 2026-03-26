#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int A[1000000];
int indexes[1000000];
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;


    int index;
    for(int i=0; i<N; i++) {
        cin >> A[i];

        if(dp.empty() || dp.back() < A[i]) {
            dp.push_back(A[i]);
            index = i;
            indexes[i] = dp.size()-1;
        }
        else {
            int lBound = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
            dp[lBound] = A[i];
            indexes[i] = lBound;
        }
    }

    cout << dp.size() << '\n';

    stack<int> sol;
    sol.push(A[index]);
    for(int i=index-1; i>=0; i--) {
        if(indexes[index]-1 == indexes[i]) {
            sol.push(A[i]);
            index = i;
        }
    }

    while(!sol.empty()) {
        cout << sol.top() << ' ';
        sol.pop();
    }
}
