#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    vector<int> count;
    for (int t: tangerine) {
        ++m[t];
    }
    for (auto t: m) {
        count.push_back(t.second);
    }
    sort(count.begin(), count.end(), greater<>());
    for (int i=0; i<count.size(); ++i) {
        ++answer;
        k -= count[i];
        if (k <= 0) {
            break;
        }
    }
    
    return answer;
}