#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    const int MOD = 1234567;
    
    int i = 1;
    int prev = 1, pprev = 0;
    
    while (i++ <= n) {
        int cur = (prev + pprev) % MOD;
        
        pprev = prev;
        prev = cur;
    }
    
    return prev;
}