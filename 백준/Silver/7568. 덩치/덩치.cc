#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int, int> people[50];
    int grade[50];
    int N;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> people[i].first >> people[i].second;
        grade[i] = 1;
    }

    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(people[i].first>people[j].first && people[i].second>people[j].second)
                grade[j]++;
            else if(people[i].first<people[j].first && people[i].second<people[j].second)
                grade[i]++;
        }
    }

    for(int i=0; i<N; i++)
        cout << grade[i] << '\n';
}