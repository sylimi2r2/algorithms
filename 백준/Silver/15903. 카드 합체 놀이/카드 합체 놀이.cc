#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int n, m;
    int input;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> input;
        pq.push(input);
    }

    long long a, b, sum;
    for(int i=0; i<m; i++) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum = a+b;
        pq.push(sum);
        pq.push(sum);
    }

    sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum;
}
