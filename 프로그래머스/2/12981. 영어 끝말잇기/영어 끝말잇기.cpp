#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> s;
    s.insert(words[0]);
    
    for (int i=1; i<words.size(); ++i) {
        if ((s.find(words[i]) != s.end()) || 
            (words[i][0] != words[i - 1][words[i - 1].size() - 1])) {
            return {i % n + 1, i / n + 1};
        }
        
        s.insert(words[i]);
    }
    
    return {0, 0};
}