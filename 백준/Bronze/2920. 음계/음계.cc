#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool aFlag = false;
    bool dFlag = false;

    int previous;
    int scale;
    cin >> previous;

    for(int i=0; i<7; i++) {
        cin >> scale;
        if(scale > previous) aFlag = true;
        else dFlag = true;
        previous = scale;
    }

    if(aFlag && !dFlag) cout << "ascending";
    else if(!aFlag && dFlag) cout << "descending";
    else cout << "mixed";

}
