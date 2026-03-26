#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int angle[3], sum = 0;

    for(int i=0; i<3; i++) {
        cin >> angle[i];
        sum += angle[i];
    }

    if(sum == 180) {
        if(angle[0]==angle[1] && angle[1]==angle[2])
            cout << "Equilateral";
        else if(angle[0]==angle[1] || angle[0]==angle[2] || angle[1]==angle[2])
            cout << "Isosceles";
        else
            cout << "Scalene";
    }
    else
        cout << "Error";
}
