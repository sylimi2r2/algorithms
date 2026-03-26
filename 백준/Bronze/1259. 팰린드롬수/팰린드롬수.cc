#include <iostream>
#include <string>
using namespace std;

int main() {
    while(true) {
        string s; cin >> s;
        if(s == "0") break;

        int len = s.length();
        if(len == 1) cout << "yes" << "\n";
        for(int i=0; i<len/2; i++) {
            if(s[i] != s[len-i-1]) {
                cout << "no" << "\n";
                break;
            }
            if(i == len/2-1) cout <<"yes" << "\n";
        }
    }
}
