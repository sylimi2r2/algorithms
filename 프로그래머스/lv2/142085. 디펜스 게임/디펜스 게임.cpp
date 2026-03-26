#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    int N = enemy.size();
    while (answer < N) {
        pq.push(enemy[answer]);
        if (pq.size() > k) {
            n -= pq.top();
            pq.pop();
        }
        if (n < 0) {
            return answer;
        }
        ++answer;
    }
    return N;
}