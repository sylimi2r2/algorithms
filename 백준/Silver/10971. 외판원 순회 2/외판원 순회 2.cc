#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> city(N);
    vector<vector<int>> W(N, vector<int>(N));
    for (int i=0; i<N; ++i) {
        city[i] = i;
        for (int j=0; j<N; ++j) {
            cin >> W[i][j];
        }
    }

    int ANS = 10'000'001;
    do {
        int tmp = W[city[N-1]][city[0]];
        if (tmp == 0)
            break;
        bool flag = true;
        for (int i=0; i<N-1; ++i) {
            if (W[city[i]][city[i + 1]] == 0) {
                flag = false;
                break;
            }
            tmp += W[city[i]][city[i + 1]];
        }

        if (flag)
            ANS = min(ANS, tmp);
    } while (next_permutation(city.begin(), city.end()));

    cout << ANS;
}