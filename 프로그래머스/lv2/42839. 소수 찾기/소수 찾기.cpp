#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_set<int> nums;
int cnt[10] = {0, };

bool isPrime(int num) {
    if (num == 0 || num == 1)
        return false;
    
    for (int i=2; i<=sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void combineNums(int cur, bool started) {
    if (started)
        nums.insert(cur);
    
    for (int i=0; i<10; ++i) {
        if (cnt[i]) {
            --cnt[i];
            if (!started && i == 0) {
                combineNums(0, true);
            }
            else {
                combineNums(cur * 10 + i, true);
            }
            ++cnt[i];
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    for (char n: numbers) {
        ++cnt[n - '0'];
    }
    combineNums(0, false);
    
    for (int num: nums) {
        if (isPrime(num))
            ++answer;
    }
    
    return answer;
}