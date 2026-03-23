#include <iostream>

using namespace std;

int n;
char S[10][10];
int sol[10];

bool dfs(int cnt) {
    if (cnt == n) {
        for (int i=0; i<n; ++i) {
            cout << sol[i] << ' ';
        }
        return true;
    }

    int left, right;
    if (S[cnt][cnt] == '+') {
        left = 1;
        right = 10;
    }
    else if (S[cnt][cnt] == '-') {
        left = -10;
        right = -1;
    }
    else {
        left = 0;
        right = 0;
    }

    for (int pick=left; pick<=right; ++pick) {
        bool flag = true;
        int tmp = pick;
        for (int i = cnt-1; i>=0; --i) {
            tmp += sol[i];
            if ((tmp > 0 && S[i][cnt] != '+') ||
                (tmp == 0 && S[i][cnt] != '0') ||
                (tmp < 0 && S[i][cnt] != '-')) {
                flag = false;
                break;
            }
        }

        if (flag) {
            sol[cnt] = pick;
            if (dfs(cnt + 1))
                return true;
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    string input;
    cin >> input;
    int idx = 0;
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            S[i][j] = input[idx++];
        }
    }

    dfs(0);
}