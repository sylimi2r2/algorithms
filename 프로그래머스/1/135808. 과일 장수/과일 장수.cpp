#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int S = score.size();
    sort(score.rbegin(), score.rend());
    for (int i=0; i<S; i+=m) {
        if (i + m - 1 < S) {
            answer += m * (score[i + m - 1]);
        }
    }
    return answer;
}