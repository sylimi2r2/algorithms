#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    for (int plz: d) {
        if (budget >= plz) {
            budget -= plz;
            ++answer;
        }
        else {
            break;
        }
    }
    return answer;
}