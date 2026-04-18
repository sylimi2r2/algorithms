#include <string>
#include <vector>

using namespace std;

int steal(vector<int>& money, int start, int n) {
    int pprev, prev, cur;
    pprev = money[start];
    prev = max(money[start], money[start + 1]);
    
    for (int i=start+2; i<n+start-1; ++i) {
        cur = max(prev, pprev + money[i]);
        pprev = prev;
        prev = cur;
    }
    
    return cur;
}

int solution(vector<int> money) {
    int n = money.size();
    
    return max(steal(money, 0, n), steal(money, 1, n));
}