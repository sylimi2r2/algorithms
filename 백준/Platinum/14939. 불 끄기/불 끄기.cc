#include <iostream>
using namespace std;

bool map[10][10];
bool cas[10][10];
pair<int, int> direction[5] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void push(int r, int c) {
    for (pair<int, int> d: direction) {
        int curR = r + d.first;
        int curC = c + d.second;
        if (curR < 0 || curR > 9 || curC < 0 || curC > 9) {
            continue;
        }
        cas[curR][curC] = !cas[curR][curC];
    }
}

void init() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cas[i][j] = map[i][j];
        }
    }
}

void solving() {
    int sol = 101;
    for (int cases = 0; cases < 1024; ++cases) {
        bool flag = true;
        int cnt = 0;
        init();
        for (int i = 0; i < 10; ++i) {
            if (cases & (1 << i)) {
                push(0, i);
                ++cnt;
            }
        }

        for (int i = 1; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (cas[i - 1][j]) {
                    push(i, j);
                    ++cnt;
                }
            }
        }

        for (int i = 0; i < 10; ++i) {
            if (cas[9][i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            sol = min(sol, cnt);
        }
    }

    cout << (sol == 101 ? -1 : sol);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 10; ++i) {
        string input;
        cin >> input;
        for (int j=0; j<10; j++) {
            if (input[j] == 'O') {
                map[i][j] = true;
            }
            else {
                map[i][j] = false;
            }
        }
    }

    solving();
}
