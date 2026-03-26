#include <iostream>
using namespace std;

#define INF 1000000
int nums[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, S;
    cin >> N >> S;
    for(int i=0; i<N; i++)
        cin >> nums[i];

    int sol = INF;
    int left = 0, right = 0;
    int sum = 0;
    while(true) {
        if(sum >= S) {
            sol = min(sol, right-left);
            if(left<right) {
                sum -= nums[left++];
            }
            else if(left==right)
                break;
        }
        else {
            if(right==N)
                break;
            else
                sum += nums[right++];
        }
    }

    if(sol == INF)
        cout << 0;
    else
        cout << sol;
}
