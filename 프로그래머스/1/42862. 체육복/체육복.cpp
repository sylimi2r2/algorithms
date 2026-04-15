#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> cnt(n + 2, 1);
    for (int& l: lost) {
        --cnt[l];
    }
    for (int& r: reserve) {
        ++cnt[r];
    }
    
    for (int i=1; i<=n; ++i) {
        if (cnt[i] == 0) {
            if (cnt[i - 1] == 2) {
                cnt[i - 1] = 1;
                cnt[i] = 1;
            } else if (cnt[i + 1] == 2) {
                cnt[i + 1] = 1;
                cnt[i] = 1;
            }
        } 
        if (cnt[i] != 0) {
            ++answer;
        }
    }
    
    return answer;
}