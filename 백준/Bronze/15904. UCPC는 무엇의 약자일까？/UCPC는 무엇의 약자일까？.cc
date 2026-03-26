#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string UCPC = "UCPC";
    string input;
    int check = 0;
    getline(cin, input);

    for(char c : input) {
        if(c==UCPC[check])
            check++;
    }

    cout << "I " << (check==4 ? "love " : "hate ") << "UCPC";
}
