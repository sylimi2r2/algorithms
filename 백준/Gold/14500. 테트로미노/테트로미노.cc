#include <iostream>

using namespace std;

int N, M;
int board[500][500];
constexpr int blocks[19][3][2] = {
        // O
        {{0, 1}, {1, 0}, {1, 1}},

        // I
        {{0, 1}, {0, 2}, {0, 3}},
        {{1, 0}, {2, 0}, {3, 0}},

        // T
        {{0, 1}, {0, 2}, {1, 1}},
        {{1, 0}, {2, 0}, {1, -1}},
        {{0, -1}, {0, -2}, {-1, -1}},
        {{-1, 0}, {-2, 0}, {-1, 1}},

        // S
        {{1, 0}, {1, 1}, {2, 1}},
        {{0, -1}, {1, -1}, {1, -2}},

        // S rev
        {{1, 0}, {1, -1}, {2, -1}},
        {{0, -1}, {-1, -1}, {-1, -2}},

        // L
        {{1, 0}, {2, 0}, {2, 1}},
        {{0, -1}, {0, -2}, {1, -2}},
        {{-1, 0}, {-2, 0}, {-2, -1}},
        {{0, 1}, {0, 2}, {-1, 2}},

        // L rev
        {{1, 0}, {2, 0}, {2, -1}},
        {{0, -1}, {0, -2}, {-1, -2}},
        {{-1, 0}, {-2, 0}, {-2, 1}},
        {{0, 1}, {0, 2}, {1, 2}}
};

bool inRange(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M)
        return false;

    return true;
}

int maxBlock(int i, int j) {
    int ret = 0;
    for (const auto & block : blocks) {
        bool flag = true;
        int tmp = board[i][j];
        for (auto n : block) {
            int nI = i + n[0];
            int nJ = j + n[1];
            if (!inRange(nI, nJ)) {
                flag = false;
                break;
            }
            tmp += board[nI][nJ];
        }
        if (flag)
            ret = max(ret, tmp);
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            ans = max(ans, maxBlock(i, j));
        }
    }

    cout << ans;
}