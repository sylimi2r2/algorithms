#include <iostream>
using namespace std;

int count = 0;
int N, r, c;

void sol(int size, int x, int y) {
    if(x == c && y == r) {
        cout << count << '\n';
        exit(0);
    }
    if(r<(y+size) && r>=y && c<(x+size) && c>=x) {
        int divide = size/2;
        sol(divide, x, y);
        sol(divide, x+divide, y);
        sol(divide, x, y+divide);
        sol(divide, x+divide, y+divide);
    }
    else {
        count += size*size;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> r >> c;
    int size = 1 << N;
    sol(size, 0, 0);
}
