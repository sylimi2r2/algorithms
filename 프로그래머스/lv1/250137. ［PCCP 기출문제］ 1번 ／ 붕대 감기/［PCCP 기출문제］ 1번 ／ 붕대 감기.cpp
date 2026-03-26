#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int stack = 0;
    int limit = attacks[attacks.size() - 1][0];
    map<int, int> attack;
    
    for (int i=0; i<attacks.size(); ++i) {
        attack.insert({attacks[i][0], attacks[i][1]});
    }
    for (int time=1; time<=limit; ++time) {
        if (attack[time] != 0) {
            answer -= attack[time];
            stack = 0;
        }
        else {
            answer += bandage[1];
            if (++stack == bandage[0]) {
                answer += bandage[2];
                stack = 0;
            }
            if (answer > health) {
                answer = health;    
            }
        }
        if (answer <= 0) {
            return - 1;
        }
    }
    return answer;
}