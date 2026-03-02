#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char alphabets[15];
char picks[15];

bool isVowel(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return true;

    return false;
}

void dfs(int cnt, int prev) {
    if (cnt == L) {
        int vowels = 0;
        for (int i=0; i<L; ++i) {
            if (isVowel(picks[i]))
                ++vowels;
        }
        if (vowels >= 1 && L - vowels >= 2) {
            for (int i=0; i<L; ++i) {
                cout << picks[i];
            }
            cout << '\n';
        }

        return;
    }

    for (int i=prev+1; i<C; ++i) {
        picks[cnt] = alphabets[i];
        dfs(cnt + 1, i);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;
    for (int i=0; i<C; ++i) {
        cin >> alphabets[i];
    }
    sort(alphabets, alphabets + C);

    dfs(0, -1);
}