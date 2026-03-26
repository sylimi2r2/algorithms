#include <iostream>
using namespace std;

int N, M;
int six = 1001, one = 1001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    int s, o;
    while(M--) {
        cin >> s >> o;
        six = min(six, s);
        one = min(one, o);
    }

    int cost =  min(N*one, N/6*six + (N%6 ? min(six, N%6*one) : 0));
    cout << cost;
}