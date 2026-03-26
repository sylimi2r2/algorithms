#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        vector<pair<int, int>> people;
        int N;
        cin >> N;
        for(int i=0; i<N; i++) {
            int paper, face;
            cin >> paper >> face;
            people.push_back({paper, face});
        }
        sort(people.begin(), people.end());

        int sol = 1;
        int MIN = people[0].second;
        for(int i=1; i<N; i++) {
            if(people[i].second < MIN) {
                sol++;
                MIN = people[i].second;
            }
        }

        cout << sol << '\n';
    }
}
