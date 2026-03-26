#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<vector<int>> set;
    int SIZE = brown + yellow;
    for (int i=1; i*i<=SIZE; ++i) {
        if (SIZE % i == 0) {
            set.push_back({SIZE/i, i});
        }
    }
    
    for (vector<int> p: set) {
        int x = p[0];
        int y = p[1];
        if (2 * x + 2 * y - 4 == brown) {
            return p;
        }
    }
}