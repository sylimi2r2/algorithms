#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 1251;
    vector<int> v;
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<picks[i]; ++j) {
            v.push_back(i);
        }
    }
    
    int p = v.size();
    int m = minerals.size();
    
    do {
        int tmp = 0;
        int i = 0, j = 0;
        int cnt = 0;
        
        while (i < p && j < m) {
            int pick = v[i];
            if (pick == 0) {
                int can = min(5, m - j);
                tmp += can;
                j += can;
                ++i;
                continue;
            }
            
            switch (minerals[j++][0]) {
                case 'd': {
                    if (pick == 1) {
                        tmp += 5;
                    } else {
                        tmp += 25;
                    }
                    
                    break;
                }
                case 'i': {
                    if (pick == 1) {
                        tmp += 1;
                    } else {
                        tmp += 5;
                    }
                    
                    break;
                }
                default: {
                    tmp += 1;
                }
            }
            
            if (++cnt == 5) {
                ++i;
                cnt = 0;
            }
        }
        
        answer = min(answer, tmp);
    } while (next_permutation(v.begin(), v.end()));
        
    return answer;
}