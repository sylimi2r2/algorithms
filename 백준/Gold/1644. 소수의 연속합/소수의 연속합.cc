#include <iostream>
#include <vector>
using namespace std;

int N, sol = 0;
bool prime[4000001];
vector<int> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for(int i=2; i<=N; i++) {
        prime[i] = 1;
    }
    for(int i=2; i<=N; i++) {
        if(prime[i] == 0)
            continue;

        for(int j=2*i; j<=N; j+=i) {
            prime[j] = 0;
        }
    }

    for(int i=2; i<=N; i++) {
        if(prime[i] == 1)
            nums.push_back(i);
    }

    int sum = 0;
    int left = 0, right = 0;

    while(true) {
        if(sum > N) {
            sum -= nums[left++];
        }
        else if(sum < N) {
            if(right == nums.size())
                break;
            sum += nums[right++];
        }
        else {
            sol++;
            if(right == nums.size())
                break;
            sum += nums[right++];
        }
    }

    cout << sol;
}
