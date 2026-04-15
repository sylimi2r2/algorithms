#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int n = name.size();
    
    int ud = 0;
    int lr = n - 1;
    
    for (int i=0; i<n; ++i) {
        int target = name[i] - 'A';
        ud += (target < 13 ? target : 26 - target);
        
        if (i > 0 && name[i] == 'A') continue;
        
        int next = i + 1;
        while (next < n && name[next] == 'A') ++next;
        
        lr = min(lr, min(2 * i + (n - next), i + 2 * (n - next)));
    }
    
    
    return ud + lr;
}