#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> have(n + 2, 1);
    for (int l: lost) {
        --have[l];
    }
    for (int r: reserve) {
        ++have[r];
    }
    for (int i=1; i<=n; ++i) {
        if (have[i] == 0) {
            if (have[i - 1] == 2) {
                have[i] = 1;
                have[i - 1] = 1;
            }
            else if (have[i + 1] == 2) {
                have[i] = 1;
                have[i + 1] = 1;
            }
        }
        if (have[i] != 0)
            ++answer;
    }
    return answer;
}