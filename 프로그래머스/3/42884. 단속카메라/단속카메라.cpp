#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
       return a[1] < b[1]; 
    });
    
    
    int MAX = -30001;
    for (vector<int>& r: routes) {
        if (r[0] > MAX) {
            ++answer;
            MAX = r[1];
        }
    }
    
    return answer;
}