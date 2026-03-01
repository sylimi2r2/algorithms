#include <iostream>
#include <vector>
using namespace std;

int N, M;

void print(vector<int> &s) {
    for(int &num : s) {
        cout << num << ' ';
    }
    cout << '\n';
}

void sol(int n, vector<int> s) {
    if(s.size() == M) {
        print(s);
        return;
    }
    if(n > N)
        return;

    s.push_back(n);
    sol(n + 1, s);
    s.erase(s.end()-1);
    sol(n + 1, s);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> s;
    cin >> N >> M;

    sol(1, s);
    return 0;
}
