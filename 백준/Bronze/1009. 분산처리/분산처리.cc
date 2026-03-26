#include <iostream>
#include <vector>
using namespace std;

vector<int> save[10] = {{0},
                        {1},
                        {2, 4, 8, 6},
                        {3, 9, 7, 1},
                        {4, 6},
                        {5},
                        {6},
                        {7, 9, 3, 1},
                        {8, 4, 2, 6},
                        {9, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    int a, b;

    cin >> T;
    while (T--) {
        cin >> a >> b;
        a = a % 10;
        --b;
        b = b % save[a].size();
        cout << (save[a][b] == 0 ? 10 : save[a][b]) << '\n';
    }
}
/*
1
2 4 8 6 2
3 9 7 1 3
4 6 4 6
5 5 5 5
6 6 6 6
7 9 3 1 7
8 4 2 6 8
9 1 9
 */
