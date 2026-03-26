#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> course;
priority_queue<int> room;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++) {
        int S, T;
        cin >> S >> T;
        course.emplace_back(S, T);
    }
    sort(course.begin(), course.end());

    room.push(-course[0].second);

    for(int i=1; i<course.size(); i++) {
        if(-room.top() <= course[i].first) {
            room.pop();
        }
        room.push(-course[i].second);
    }

    cout << room.size();

}
