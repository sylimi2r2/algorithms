#include <iostream>
using namespace std;

int N;
int sum = 0;
int answer;
pair<int, int> checkpoint[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> checkpoint[i].first >> checkpoint[i].second;
    }

    for (int i = 1; i < N; i++) {
        sum += abs(checkpoint[i].first - checkpoint[i - 1].first) +
               abs(checkpoint[i].second - checkpoint[i - 1].second);
    }
    answer = sum;

    for (int i = 1; i < N - 1; i++) {
        answer = min(answer, sum - (abs(checkpoint[i].first - checkpoint[i - 1].first) +
                                    abs(checkpoint[i].second - checkpoint[i - 1].second)) -
                             (abs(checkpoint[i+1].first - checkpoint[i].first) +
                              abs(checkpoint[i+1].second - checkpoint[i].second)) +
                             (abs(checkpoint[i + 1].first - checkpoint[i - 1].first) +
                              abs(checkpoint[i + 1].second - checkpoint[i - 1].second)));
    }

    cout << answer;
}
