#include <string>
#include <vector>

using namespace std;

int guess[5];
int N;
vector<vector<int>> question;
vector<int> answer;
int ret = 0;

bool check() {
    for (int i=0; i<question.size(); ++i) {
        int match = 0;
        int left = 0, right = 0;
        while (left < 5 && right < 5) {
            if (guess[left] == question[i][right]) {
                ++match;
                ++left;
                ++right;
            }
            else if(guess[left] < question[i][right]) {
                ++left;
            }
            else {
                ++right;
            }
        }
        if (match != answer[i])
            return false;
    }
    return true;
}

void generate(int cnt, int num) {
    if (cnt == 5) {
        if (check()) {
            ++ret;
        }
        return;
    }
    for (int i=num; i<=N-4+cnt; ++i) {
        guess[cnt] = i;
        generate(cnt+1, i+1);
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N = n;
    question = q;
    answer = ans;
    generate(0, 1);
    return ret;
}