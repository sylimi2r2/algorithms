#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int tmp = x;
    int y = 0;
    while (tmp > 0) {
        y += tmp % 10;
        tmp /= 10;
    }
    return (x%y == 0 ? true : false);
}