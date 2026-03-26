#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<pair<int, int>> s;
    int N, tmp, same;
    long long sol = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        same = 1;
        cin >> tmp;
        while (!s.empty()) {
            if (s.top().first < tmp) {
                sol += s.top().second;
                s.pop();
            }
            else if (s.top().first == tmp) {
                sol += s.top().second;
                same += s.top().second;
                s.pop();
            }
            else {
                sol++;
                break;
            }
        }
        s.push({tmp, same});

    }

    cout << sol;
}
