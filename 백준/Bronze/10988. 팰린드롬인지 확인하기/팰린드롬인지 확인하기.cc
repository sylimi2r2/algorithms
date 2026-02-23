#include <iostream>

using namespace std;

bool isPalindrome(const string& str) {
    int len = str.length();
    for (int i=0; i<len/2; ++i) {
        if (str[i] != str[len-i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;

    cin >> s;
    cout << (isPalindrome(s) ? 1 : 0);
}