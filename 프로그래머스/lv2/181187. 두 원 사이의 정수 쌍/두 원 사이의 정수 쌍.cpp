#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long R1 = (long long)r1 * r1;
    long long R2 = (long long)r2 * r2;
    for (int i=1; i<=r2; ++i) {
        long long xx = (long long)i * i;
        int lo = 0;
        if (r1 > i) {
            lo = ceil(sqrt(R1 - xx));
        }
        int hi = floor(sqrt(R2 - xx));
        answer += hi - lo + 1;
    }
    answer *= 4;
    return answer;
}