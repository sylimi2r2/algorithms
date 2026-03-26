#include <iostream>
#include <string>
using namespace std;

int main() {
    int num[26] = {0,};
    int max = 0;
    int where = 0;
    bool flag = false;
    string str; cin >> str;

    for(char c : str){
        int index = toupper(c);
        num[index - 'A']++;
    }

    for(int i=0; i<26; i++) {
        if(num[i] > max){
            max = num[i];
            where = i;
            flag = false;
        }
        else if(num[i] == max) flag = true;
    }

    if(flag) cout << "?";
    else cout << char(where + 'A');
}
