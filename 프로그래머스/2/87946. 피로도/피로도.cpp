#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int n = dungeons.size();
    vector<int> order(n);
    for (int i=0; i<n; ++i) {
        order[i] = i;
    }
    
    do {
        int cnt = 0;
        int hp = k;
        
        for (int i=0; i<n; ++i) {
            vector<int> dungeon = dungeons[order[i]];
            
            if (hp >= dungeon[0]) {
                hp -= dungeon[1];
                ++cnt;
            } else break;
        }
        
        answer = max(answer, cnt);
    } while (next_permutation(order.begin(), order.end()));
    
    return answer;
}