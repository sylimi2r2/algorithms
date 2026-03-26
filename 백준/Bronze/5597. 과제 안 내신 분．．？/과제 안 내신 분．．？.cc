#include <iostream>
using namespace std;

int main() {
    bool student[30] = {0,};
    int s;
    for(int i=0; i<28; ++i) {
        cin >> s;
        student[s-1] = 1;
    }
    for(int i=0; i<30; ++i) {
        if(!student[i]) cout << i+1 << endl;
    }
    return 0;
}