#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, cnt = 0;
    cin >> N;

    while(N--) {
        bool check[26] = {0,};
        bool flag = true;
        string input;
        cin >> input;
        for(int i=0; i<input.length(); i++) {
            if(check[input[i]-'a']) {
                if(input[i-1] != input[i]) {
                    flag = false;
                    break;
                }
            }
            else
                check[input[i]-'a'] = true;
        }
        if(flag)
            cnt++;
    }

    cout << cnt;
}
