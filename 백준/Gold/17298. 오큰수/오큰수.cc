#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> s;
int nums[1000000];
int NGE[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> nums[i];

    for(int i=N-1; i>=0; i--) {
        while(!s.empty()) {
            if(nums[i]>=s.top())
                s.pop();
            else
                break;
        }
        if(s.empty())
            NGE[i] = -1;
        else
            NGE[i] = s.top();

        s.push(nums[i]);
    }

    for(int i=0; i<N; i++)
        cout << NGE[i] << ' ';
}
