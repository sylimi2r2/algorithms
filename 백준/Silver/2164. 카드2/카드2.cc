#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;

    queue<int> cards;
    for(int i=1; i<=N; i++) {
        cards.push(i);
    }

    while(cards.size() != 1) {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front();
}
