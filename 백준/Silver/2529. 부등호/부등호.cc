#include <iostream>
#include <vector>

using namespace std;

int k;
char signs[9];
bool picked[10];
vector<int> MAX, MIN;
vector<int> sol;

bool isSmaller(vector<int> &a, vector<int> &b) {
    for (int i=0; i<=k; ++i) {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }

    return false;
}

// start from cnt = 1
void dfs(int cnt) {
    if (cnt > k) {
        if (isSmaller(sol, MIN))
            MIN = sol;
        if (isSmaller(MAX, sol))
            MAX = sol;

        return;
    }

    for (int i=0; i<10; ++i) {
        if (!picked[i]) {
            switch (signs[cnt - 1]) {
                case '<': {
                    if (sol[cnt - 1] < i) {
                        picked[i] = true;
                        sol[cnt] = i;
                        dfs(cnt + 1);
                        picked[i] = false;
                    }
                    break;
                }
                case '>': {
                    if (sol[cnt - 1] > i) {
                        picked[i] = true;
                        sol[cnt] = i;
                        dfs(cnt + 1);
                        picked[i] = false;
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> k;
    for (int i=0; i<k; ++i) {
        cin >> signs[i];
    }
    MIN = vector<int>(k+1, 9);
    MAX = vector<int>(k+1, 0);
    sol = vector<int>(k+1);

    for (int i=0; i<10; ++i) {
        picked[i] = true;
        sol[0] = i;
        dfs(1);
        picked[i] = false;
    }

    for (int i=0; i<=k; ++i) {
        cout << MAX[i];
    }
    cout << '\n';
    for (int i=0; i<=k; ++i) {
        cout << MIN[i];
    }
}