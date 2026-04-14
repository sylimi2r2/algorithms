#include <string>
#include <vector>

using namespace std;

int guess1[5] = {1, 2, 3, 4, 5};
int guess2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int guess3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> score = {0, 0, 0};
    for (int i=0; i<answers.size(); ++i) {
        int ans = answers[i];
        
        if (guess1[i % 5] == ans) ++score[0];
        if (guess2[i % 8] == ans) ++score[1];
        if (guess3[i % 10] == ans) ++score[2];
    }
    
    int MAX = max(score[0], max(score[1], score[2]));
    for (int i=0; i<3; ++i) {
        if (score[i] == MAX)
            answer.push_back(i + 1);
    }
    
    return answer;
}