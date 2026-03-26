#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    string str;
    for(int i=0; i<N; i++) {
        cin >> str;
        int score = 0;
        int previous = 0;
        int len = str.length();
        for(int j=0; j<len; j++) {
            if(str[j] == 'O') {
                previous++;
                score += previous;
            }
            else previous = 0;
        }
        cout << score << "\n";
    }
}
