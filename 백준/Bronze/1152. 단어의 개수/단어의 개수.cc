#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int cnt = 0;
    int len;

    getline(cin, str);
    len = str.length();

    for(int i=0; i<len; i++) {
        if(str[i] == ' ') {
            cnt++;
        }
    }

    if(str[0] == ' ') cnt--;
    if(str[len-1] == ' ') cnt--;

    cout << cnt+1;
}
