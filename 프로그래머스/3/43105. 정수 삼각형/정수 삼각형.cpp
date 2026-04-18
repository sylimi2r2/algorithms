#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    
    for (int i=1; i<n; ++i) {
        int m = triangle[i].size();
        triangle[i][0] += triangle[i - 1][0];
        for (int j=1; j<m-1; ++j) {
            triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        triangle[i][m - 1] += triangle[i - 1][m - 2];
    }
    
    return *max_element(triangle[n - 1].begin(), triangle[n - 1].end());
}