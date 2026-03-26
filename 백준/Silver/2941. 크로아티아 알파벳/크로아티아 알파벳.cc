#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    cin >> input;
    int sol = input.length();
    int i = 0;

    while(i<input.length()) {
        if(input[i] == 'c') {
            if(input[i+1]=='=' || input[i+1]=='-') {
                sol--;
                i += 1;
            }
        }
        else if(input[i] == 'd') {
            if(input[i+1]=='-') {
                sol--;
                i += 1;
            }
            else if(input[i+1]=='z' && input[i+2]=='=') {
                sol -= 2;
                i += 2;
            }
        }
        else if(input[i] == 'l') {
            if(input[i+1] == 'j') {
                sol--;
                i += 1;
            }
        }
        else if(input[i] == 'n') {
            if(input[i+1] == 'j') {
                sol--;
                i += 1;
            }
        }
        else if(input[i] == 's') {
            if(input[i+1] == '=') {
                sol--;
                i += 1;
            }
        }
        else if(input[i] == 'z') {
            if(input[i+1] == '=') {
                sol--;
                i += 1;
            }
        }
        i++;
    }

    cout << sol;
}
