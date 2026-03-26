#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<pair<int, int>> keypad = {{1, 0}, 
                                     {0, 3}, {1, 3}, {2, 3},
                                     {0, 2}, {1, 2}, {2, 2},
                                     {0, 1}, {1, 1}, {2, 1}};
    pair<int, int> left = {0, 0}, right = {2, 0};
    
    for (int n: numbers) {
        if (n == 1 || n == 4 || n == 7) {
            answer += 'L';
            left = keypad[n];
            continue;
        }
        if (n == 3 || n == 6 || n == 9) {
            answer += 'R';
            right = keypad[n];
            continue;
        }
        else {
            int l = abs(keypad[n].first - left.first) + abs(keypad[n].second - left.second);
            int r = abs(keypad[n].first - right.first) + abs(keypad[n].second - right.second);
            if (l < r) {
                answer += 'L';
                left = keypad[n];
                continue;
            }
            if (l > r) {
                answer += 'R';
                right = keypad[n];
                continue;
            }
            if (hand[0] == 'l') {
                answer += 'L';
                left = keypad[n];
                continue;
            }
            answer += 'R';
            right = keypad[n];
        }
    }
    return answer;
}