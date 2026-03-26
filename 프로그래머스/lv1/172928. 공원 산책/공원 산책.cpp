#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    map<char, pair<int, int>> direction = {{'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}};
    int curX, curY;
    int H = park.size(), W = park[0].size();
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (park[i][j] == 'S') {
                curX = i;
                curY = j;
            }
        }
    }
    for (string r: routes) {
        pair<int, int> d = direction[r[0]];
        int n = r[2] - '0';
        int nextX = curX, nextY = curY;
        for (int i=0; i<n; ++i) {
            nextX += d.first;
            nextY += d.second;
            if (nextX > -1 && nextX < H && nextY > -1 && nextY < W) {
                if (park[nextX][nextY] == 'X') {
                    nextX = curX;
                    nextY = curY;
                    break;
                }
            }
            else {
                nextX = curX;
                nextY = curY;
                break;
            }
        }
        curX = nextX;
        curY = nextY;
    }
    answer.push_back(curX);
    answer.push_back(curY);
    return answer;
}