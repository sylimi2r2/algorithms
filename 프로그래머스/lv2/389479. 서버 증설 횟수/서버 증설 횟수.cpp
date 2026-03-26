#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int table[24] = {0,};
    for (int i=0; i<24; ++i) {
        if (players[i] >= (table[i] + 1) * m) {
            int plus = players[i] / m - table[i];
            for (int j=0; j<k; ++j) {
                if (i + j < 24) {
                    table[i+j] += plus;   
                }
            }
            answer += plus;
        }
    }
    return answer;
}