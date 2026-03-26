#include <string>
#include <vector>

using namespace std;

const char nums[3] = {'1', '2', '4'};

string solution(int n) {
    string answer = "";
    
    while (n) {
        --n;
        answer = nums[n % 3] + answer;
        n /= 3;
        if (!n)
            break;
    }
    return answer;
}