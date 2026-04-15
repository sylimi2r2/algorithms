#include <string>
#include <vector>

using namespace std;

char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
int jumps[5] = {781, 156, 31, 6, 1};

int solution(string word) {
    int answer = 0;
    
    for (int i=0; i<word.size(); ++i) {
        for (int j=0; j<5; ++j) {
            if (word[i] == vowels[j]) {
                answer += jumps[i] * j;
                break;
            }
            
        }
    }
    answer += word.size();
    
    return answer;
}
