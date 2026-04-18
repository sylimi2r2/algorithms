#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number)
        return 1;
    
    vector<unordered_set<int>> dp(9);
    dp[1].insert(N);
    
    int a = N;
    for (int i=2; i<=8; ++i) {
        a = 10 * a + N;
        dp[i].insert(a);
        for (int j=1; j<i; ++j) {
            for (int x: dp[j]) {
                for (int y: dp[i-j]) {
                    dp[i].insert(x + y);
                    dp[i].insert(x - y);
                    dp[i].insert(x * y);
                    if (y != 0) dp[i].insert(x / y);
                }
            }
        }
        
        if (dp[i].count(number))
            return i;
    }
    
    return -1;
}