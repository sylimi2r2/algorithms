#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int len = sequence.size();
    int left = 0, right = 0;
    int i=0;
    int j=0;
    int tmp = sequence[0];
    int MAX = 987654321;
    
    while (j < len) {
        if (tmp == k) {
            if (j - i < MAX) {
                left = i;
                right = j;
                MAX = right - left;
            }
            tmp += sequence[++j];
        }
        else if (tmp > k) {
            tmp -= sequence[i++];
        }
        else {
            tmp += sequence[++j];
        }
    }
    
    answer.push_back(left);
    answer.push_back(right);
    return answer;
}