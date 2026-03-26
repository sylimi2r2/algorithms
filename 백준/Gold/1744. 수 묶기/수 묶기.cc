#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> positive;
vector<int> negative;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long sol = 0;

    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        if(input > 1)
            positive.push_back(input);
        else if(input < 1)
            negative.push_back(input);
        else
            sol++;
    }

    sort(positive.rbegin(), positive.rend());
    sort(negative.begin(), negative.end());

    int pSize = positive.size();
    int nSize = negative.size();

    for(int i=0; i<pSize; i++) {
        if(i+1 < pSize) {
            sol += positive[i]*positive[i+1];
            i++;
        }
        else
            sol += positive[i];
    }

    for(int i=0; i<nSize; i++) {
        if(i+1 < nSize) {
            sol += negative[i]*negative[i+1];
            i++;
        }
        else
            sol += negative[i];
    }

    cout << sol;
}
