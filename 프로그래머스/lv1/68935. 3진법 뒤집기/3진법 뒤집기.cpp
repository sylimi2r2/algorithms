#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n) {
    int answer = 0;
    stack<int> tmp;
    while (n > 0) {
        tmp.push(n % 3);
        n /= 3;
    }
    int exp = 1;
    while (!tmp.empty()) {
        answer += exp * tmp.top();
        tmp.pop();
        exp *= 3;
    }
    return answer;
}