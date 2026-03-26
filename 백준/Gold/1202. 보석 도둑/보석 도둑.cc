#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> jewels;
    vector<int> bags;
    int N, K;
    cin >> N >> K;

    for(int i=0; i<N; i++) {
        int M, V;
        cin >> M >> V;
        jewels.push_back({M, V});
    }
    for(int i=0; i<K; i++) {
        int capacity;
        cin >> capacity;
        bags.push_back(capacity);
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    long long sum = 0;
    priority_queue<int> pq;
    for(int b=0, j=0; b<K; b++) {
        while(j<N) {
            if(jewels[j].first <= bags[b]) {
                pq.push(jewels[j++].second);
            }
            else
                break;
        }
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
}
