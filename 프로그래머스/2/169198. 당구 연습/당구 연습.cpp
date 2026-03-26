#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (vector<int> ball: balls) {
        int rr = 987654321;
        int x, y;
        
        // left cushion
        if (startY != ball[1] || startX <= ball[0]) {
            x = -ball[0];
            y = ball[1];
            rr = min(rr, (startX - x) * (startX - x) + (startY - y) * (startY - y));    
        }
        
        // right cushion
        if (startY != ball[1] || startX >= ball[0]) {
            x = 2 * m - ball[0];
            y = ball[1];
            rr = min(rr, (startX - x) * (startX - x) + (startY - y) * (startY - y));    
        }
        
        // down cushion
        if (startX != ball[0] || startY <= ball[1]) {
            x = ball[0];
            y = -ball[1];
            rr = min(rr, (startX - x) * (startX - x) + (startY - y) * (startY - y));    
        }
        
        // up cushion
        if (startX != ball[0] || startY >= ball[1]) {
            x = ball[0];
            y = 2 * n - ball[1];
            rr = min(rr, (startX - x) * (startX - x) + (startY - y) * (startY - y));    
        }
        
        answer.push_back(rr);
    }
    return answer;
}