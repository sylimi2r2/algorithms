#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int rank[7] = {6, 6, 5, 4, 3, 2, 1};
    int missing = 0;
    int correct = 0;
    vector<bool> win(46, false);
    for (int w: win_nums) {
        win[w] = true;
    }
    for (int l: lottos) {
        if (l == 0) {
            ++missing;
        }
        else {
            if (win[l])
                ++correct;
        }
    }
    answer.push_back(rank[correct + missing]);
    answer.push_back(rank[correct]);
    return answer;
}