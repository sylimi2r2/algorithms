#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    
    for (int i=0; i<n; ++i) {
        int h = n - i;
        if (h <= citations[i])
            return h;
    }
    
    return 0;
}