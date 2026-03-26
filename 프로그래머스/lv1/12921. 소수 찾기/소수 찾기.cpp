#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> prime(n + 1, true);
    for (int i=2; i<=n; ++i) {
        if (prime[i]) {
            ++answer;
            for (int j=2*i; j<=n; j+=i) {
                prime[j] = false;   
            }
        }
    }
    return answer;
}