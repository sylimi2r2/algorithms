#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    queue<pair<int, int>> bridge;
    int cur = 0;
    int idx = 0;
    while (idx < truck_weights.size()) {
        if (cur + truck_weights[idx] <= weight) {
            cur += truck_weights[idx];
            bridge.push({truck_weights[idx], answer++});
            ++idx;
        } else {
            answer = max(answer, bridge.front().second + bridge_length);
            cur -= bridge.front().first;
            bridge.pop();
        }
    }
    
    while (!bridge.empty()) {
        answer = max(answer, bridge.front().second + bridge_length);
        bridge.pop();
    }
    
    return answer;
}