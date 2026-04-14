#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<pair<int, int>> max_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
    
    vector<bool> exists(operations.size(), false);
    int id = 0;
    
    for (string op: operations) {
        char opcode = op[0];
        int operand = stoi(op.substr(2));
        
        if (opcode == 'I') {
            max_heap.push({operand, id});
            min_heap.push({operand, id});
            exists[id++] = true;
            continue;
        }
        
        if (opcode == 'D') {
            if (operand == 1) {
                while (!max_heap.empty() && !exists[max_heap.top().second]) {
                    max_heap.pop();
                }
                
                if (!max_heap.empty()) {
                    exists[max_heap.top().second] = false;
                    max_heap.pop();
                }
            } else {
                while (!min_heap.empty() && !exists[min_heap.top().second]) {
                    min_heap.pop();
                }
                
                if (!min_heap.empty()) {
                    exists[min_heap.top().second] = false;
                    min_heap.pop();
                }
            }
        }
    }
    
    while (!max_heap.empty() && !exists[max_heap.top().second]) {
        max_heap.pop();
    }
    
    while (!min_heap.empty() && !exists[min_heap.top().second]) {
        min_heap.pop();
    }
    
    if (max_heap.empty()) {
        return {0, 0};
    }
    
    return {max_heap.top().first, min_heap.top().first};
}