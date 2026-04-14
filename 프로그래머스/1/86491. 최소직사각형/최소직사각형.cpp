#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0, height = 0;
    
    for (vector<int>& size: sizes) {
        width = max(width, max(size[0], size[1]));
        height = max(height, min(size[0], size[1]));
    }
    
    return width * height;
}