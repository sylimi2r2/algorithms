#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    priority_queue<int> pq;
    cin >> N;
    for(int i=0; i<N; i++) {
        int input;
        cin >> input;
        pq.push(-input);
    }

    int sum = 0;
    for(int i=0; i<N-1; i++) {
        int tmp = 0;
        tmp -= pq.top();
        pq.pop();
        tmp -= pq.top();
        pq.pop();
        sum += tmp;
        pq.push(-tmp);
    }

    cout << sum;
}
