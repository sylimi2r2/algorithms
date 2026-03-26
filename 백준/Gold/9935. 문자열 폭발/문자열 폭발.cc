#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str, bomb, temp;
    cin >> str >> bomb;
    int sLen = str.length();
    int bLen = bomb.length();

    for(int i=0; i<sLen; i++) {
        temp += str[i];
        if(str[i] == bomb[bLen-1]) {
            int tLen = temp.length();
            if(tLen >= bLen) {
                bool explode = true;
                int checkIdx = tLen - bLen;
                for(int j=bLen-2; j>=0; j--) {
                    if(temp[checkIdx + j] != bomb[j]) {
                        explode = false;
                        break;
                    }
                }
                if(explode)
                    temp.erase(temp.end()-bLen, temp.end());
            }
        }
    }

    if(temp.length())
        cout << temp;
    else
        cout << "FRULA";
}
