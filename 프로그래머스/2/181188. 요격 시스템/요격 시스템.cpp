#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    if (a[1] != b[1])
        return a[1] < b[1];
    else 
        return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int e = -1;
    sort(targets.begin(), targets.end(), compare);
    for (vector<int> t: targets) {
        if (t[0] >= e) {
            ++answer;
            e = t[1];
        }
    }
    return answer;
}