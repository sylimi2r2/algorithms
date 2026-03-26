#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int alphabet[26];
    fill_n(alphabet, 26, -1);
    string S; cin >> S;

    for(int i=S.length()-1; i>=0; i--) {
        alphabet[S[i] - 'a'] = i;
    }

    for(int i=0; i<26; i++) {
        cout << alphabet[i] << " ";
    }
}
