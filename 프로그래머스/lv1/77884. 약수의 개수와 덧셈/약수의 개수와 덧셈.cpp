#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    vector<int> measure(right + 1, 1);
    int answer = 0;
    for (int i=2; i<=right; ++i) {
        for (int j=i; j<=right; j+=i) {
            ++measure[j];
        }
    }
    for (int i=left; i<=right; ++i) {
        if (measure[i] % 2) {
            answer -= i;
        }
        else {
            answer += i;
        }
    }
    return answer;
}