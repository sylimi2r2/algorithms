#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void organizing(vector<vector<int>> &data, string ext, int val_ext, vector<vector<int>> &ret) {
    int mode;
    switch (ext[0]) {
        case 'c':
            mode = 0;
            break;
        case 'd':
            mode = 1;
            break;
        case 'm':
            mode = 2;
            break;
        case 'r':
            mode = 3;
            break;
    }
    
    for (vector<int> d: data) {
        if (d[mode] < val_ext) {
            ret.push_back(d);
        }
    }
}

void sorting(string sort_by, vector<vector<int>> &ret) {
    int mode;
    switch (sort_by[0]) {
        case 'c':
            mode = 0;
            break;
        case 'd':
            mode = 1;
            break;
        case 'm':
            mode = 2;
            break;
        case 'r':
            mode = 3;
            break;
    }
    
    sort(ret.begin(), ret.end(), 
         [&](vector<int> &a, vector<int> &b) -> bool {
             return a[mode] < b[mode];
         });
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    organizing(data, ext, val_ext, answer);
    sorting(sort_by, answer);
    return answer;
}