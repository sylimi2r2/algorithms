#include <string>
#include <vector>

using namespace std;

pair<int, int> direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string color = board[h][w];
    
    for (int i=0; i<4; ++i) {
        int curH = h + direction[i].first;
        int curW = w + direction[i].second;
        if (curH >= 0 && curH < board.size() && curW >= 0 && curW < board.size()) {
            if (color == board[curH][curW])
                ++answer;
        }
    }
    return answer;
}