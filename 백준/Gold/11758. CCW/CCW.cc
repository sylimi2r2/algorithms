#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int ccw(Point p1, Point p2, Point p3) {
    return ((p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p2.x));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Point p1, p2, p3;
    cin >> p1.x >> p1.y
        >> p2.x >> p2.y
        >> p3.x >> p3.y;

    int result = ccw(p1, p2, p3);
    if(result > 0)
        cout << 1;
    else if(result < 0)
        cout << -1;
    else
        cout << 0;

}
