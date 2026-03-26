#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    int mask = 1;
    for (int i=0; i<31; ++i) {
        if (n & mask) {
            ++answer;
        }
        mask = mask << 1;
    }
    return answer;
}