#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long cal = num;
    while (answer <= 500) {
        if (cal == 1) {
            break;
        }
        if (cal % 2) {
            cal = 3 * cal + 1;
        }
        else {
            cal /= 2;
        }
        ++answer;
    }
    return (answer < 500 ? answer : -1);
}