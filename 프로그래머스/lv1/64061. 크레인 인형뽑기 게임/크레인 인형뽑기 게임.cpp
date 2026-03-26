#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    int s = board.size();
    
    for (int m: moves) {
        for (int level=0; level<s; ++level) {
            int doll = board[level][m - 1];
            if (doll != 0) {
                board[level][m - 1] = 0;
                if (!basket.empty() && basket.top() == doll) {
                    basket.pop();
                    answer += 2;
                }
                else {
                    basket.push(doll);
                }
                break;
            }
        }
    }
    
    return answer;
}