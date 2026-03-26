#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    long long S;
    int num = 0;
    cin >> S;

    while(S > 0) {
        S -= ++num;
    }

    cout << (S==0 ? num : num-1);
}