#include <string>
#include <vector>

using namespace std;

const int MOD = 1234567;

int solution(int n) {
    int f0 = 0, f1 = 1;
    for (int i=2; i<=n; ++i) {
        int tmp = f0;
        f0 = f1;
        f1 = (f1 + tmp) % 1234567;
    }
    return f1;
}