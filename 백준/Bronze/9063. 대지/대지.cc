#include <iostream>
using namespace std;

#define MAX 10000
#define MIN -10000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x1=MAX, y1=MAX, x2=MIN, y2=MIN;
    int N;
    cin >> N;
    while(N--) {
        int inputX, inputY;
        cin >> inputX >> inputY;
        x1 = min(x1, inputX);
        x2 = max(x2, inputX);
        y1 = min(y1, inputY);
        y2 = max(y2, inputY);
    }

    cout << (x2-x1)*(y2-y1);
}
