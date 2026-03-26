#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int s=0; s<schedules.size(); ++s) {
        bool flag = true;
        int goal = schedules[s] + 10;
        if (goal % 100 >= 60)
            goal += 40;
        for (int day=0; day<7; ++day) {
            int today = (day + startday) % 7;
            if (today == 6 || today == 0) {
                continue;
            }
            if (timelogs[s][day] > goal) {
                flag = false;
                break;
            }
        }
        if (flag)
            ++answer;
    }
    return answer;
}