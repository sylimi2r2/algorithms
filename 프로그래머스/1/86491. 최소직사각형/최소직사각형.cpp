#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0, y = 0;
    for (vector<int> s: sizes) {
        x = max(x, max(s[0], s[1]));
        y = max(y, min(s[0], s[1]));
    }
    return x * y;
}