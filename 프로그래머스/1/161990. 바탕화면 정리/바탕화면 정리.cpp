#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = 50, minY = 50, maxX = -1, maxY = -1;
    for (int i=0; i<wallpaper.size(); ++i) {
        for (int j=0; j<wallpaper[0].size(); ++j) {
            if (wallpaper[i][j] == '#') {
                minX = min(minX, i);
                minY = min(minY, j);
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
        }
    }
    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX + 1);
    answer.push_back(maxY + 1);
    return answer;
}