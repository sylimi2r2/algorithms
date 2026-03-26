#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

vector<int> solution(int n, int m) {
    int GCD = gcd(n, m);
    int LCM = n * m / GCD;
    return {GCD, LCM};
}