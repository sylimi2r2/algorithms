#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int tmp = section[0];
    for (int s: section) {
        if (tmp <= s) {
            ++answer;
            tmp = s + m;
        }
    }
    return answer;
}