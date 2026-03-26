#include <string>
#include <vector>
#include <cmath>

using namespace std;

int finding(long long num) {
    if (num == 1)
        return 0;
    
    int max = 0;
    
    for (int i=2; i<=sqrt(num); ++i) {
        if (num % i == 0) {
            max = i;
            if (num / i <= 10000000) {
                return num / i;
            }
        }
    }
    
    if (!max) return 1;
    return max;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for (long long i=begin; i<=end; ++i) {
        answer.push_back(finding(i));
    }
    return answer;
}