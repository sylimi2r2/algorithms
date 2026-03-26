#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int LCS[s1.length()+1][s2.length()+1];
    int sol = 0;

    for(int i=0; i<=s1.length(); i++) {
        for(int j=0; j<=s2.length(); j++) {
            if(i == 0 || j == 0)
                LCS[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) {
                LCS[i][j] = LCS[i-1][j-1]+1;
                sol = max(sol, LCS[i][j]);
            }
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }

    cout << sol;
}
