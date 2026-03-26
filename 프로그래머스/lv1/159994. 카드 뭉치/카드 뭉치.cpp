#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0, idx2 = 0;
    int size1 = cards1.size(), size2 = cards2.size();
    for (string g: goal) {
        if (idx1 < size1 && g == cards1[idx1]) {
            ++idx1;
            continue;
        }
        if (idx2 < size2 && g == cards2[idx2]) {
            ++idx2;
            continue;
        }
        else {
            return "No";
        }
    }
    return "Yes";
}