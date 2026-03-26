#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int len[3];

    while(true) {
        cin >> len[0] >> len[1] >> len[2];
        if(!len[0] && !len[1] && !len[2]) break;

        for(int i=1; i<3; i++) {
            if(len[i] > len[0]) {
                int tmp = len[0];
                len[0] = len[i];
                len[i] = tmp;
            }
        }

        if(len[0]*len[0] == len[1]*len[1] + len[2]*len[2]) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
}