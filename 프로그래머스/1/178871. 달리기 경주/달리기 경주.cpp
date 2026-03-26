#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> rank;
    for (int i=0; i<players.size(); ++i) {
        rank.insert({players[i], i});
    }
    for (string call: callings) {
        int r = rank[call];
        players[r] = players[r - 1];
        players[r - 1] = call;
        --rank[call];
        ++rank[players[r]];
    }
    return players;
}