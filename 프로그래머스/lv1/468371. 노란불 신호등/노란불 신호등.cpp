#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool isYellow(int t, vector<int> &signal) {
    int cur = (t - 1) % (signal[0] + signal[1] + signal[2]);
    
    return (cur >= signal[0] && cur < signal[0] + signal[1]);
}

int solution(vector<vector<int>> signals) {
    int limit = 1;
    for (vector<int> signal: signals) {
        limit = lcm(limit, signal[0] + signal[1] + signal[2]);    
    }
    
    for (int t=1; t<=limit; ++t) {
        bool flag = true;
        for (vector<int> signal: signals) {
            if (!isYellow(t, signal)) {
                flag = false;
                break;
            }
        }
        
        if (flag)
            return t;
    }
    
    
    return -1;
}