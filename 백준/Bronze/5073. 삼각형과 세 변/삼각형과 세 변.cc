#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int lines[3];
    while(true) {
        cin >> lines[0] >> lines[1] >> lines[2];
        if(lines[0]==0 && lines[1]==0 && lines[2]==0)
            break;

        sort(lines, lines+3);

        if(lines[2] >= lines[0]+lines[1])
            cout << "Invalid\n";
        else {
            if(lines[0]==lines[1] && lines[1]==lines[2])
                cout << "Equilateral\n";
            else if(lines[0]==lines[1] || lines[1]==lines[2])
                cout << "Isosceles\n";
            else
                cout << "Scalene\n";
        }
    }
}
