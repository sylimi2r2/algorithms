#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int sizeT = t.size(), sizeP = p.size();
    for (int i=0; i<sizeT-sizeP+1; ++i) {
        for (int j=0; j<sizeP; ++j) {
            if (t[i + j] < p[j]) {
                ++answer;
                break;
            }
            else if (t[i + j] == p[j]) {
                if (j == sizeP - 1) {
                    ++answer;
                    break;
                }
                else {
                    continue;
                }
            }
            else 
                break;
            
        }
    }
    return answer;
}