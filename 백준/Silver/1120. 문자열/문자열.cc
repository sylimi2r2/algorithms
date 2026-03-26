#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int sol = 50;
    for(int i=0; i<=B.length()-A.length(); i++) {
        int tmp = 0;
        for(int j=0; j<A.length(); j++) {
            if(A[j] != B[i+j])
                tmp++;
        }
        sol = min(sol, tmp);
    }

    cout << sol;
}