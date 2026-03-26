#include <iostream>
#include <vector>
using namespace std;

int N;
int input;
int bound = 0;
vector<int> player;
bool picked[1000001] = {0,};
int card[1000001] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        bound = max(bound, input);
        player.emplace_back(input);
        picked[input] = true;
    }

    for (int p: player) {
        for (int i = 2 * p; i <= bound; i += p) {
            if(picked[i]) {
                card[p]++;
                card[i]--;
            }
        }
    }

    for (int p: player) {
        cout << card[p] << ' ';
    }
}