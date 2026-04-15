#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int cnt = brown + yellow;
    int w = brown / 2 - 1;
    int h = 3;
    
    while (w >= h) {
        if (w * h == cnt)
            return {w, h};
        
        --w;
        ++h;
    }
}