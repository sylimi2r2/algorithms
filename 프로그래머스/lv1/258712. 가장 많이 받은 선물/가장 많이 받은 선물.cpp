#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int N = friends.size();
    vector<vector<int>> record;
    vector<int> exp(N, 0);
    vector<int> will(N, 0);
    map<string, int> id;
    
    for (int i=0; i<N; ++i) {
        vector<int> tmp;
        for (int j=0; j<N; ++j) {
            tmp.push_back(0);
        }
        record.push_back(tmp);
    }
    for (int i=0; i<N; ++i) {
        id.insert({friends[i], i});
    }
    for (string gift: gifts) {
        string giver, receiver;
        istringstream ss(gift);
        ss >> giver >> receiver;
        int id_giver = id[giver], id_receiver = id[receiver];
        ++record[id_giver][id_receiver];
        --exp[id_giver];
        ++exp[id_receiver];
    }
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            if (record[i][j] > record[j][i]) {
                ++will[i];
            }
            else if (record[i][j] < record[j][i]) {
                ++will[j];
            }
            else {
                if (exp[i] > exp[j]) {
                    ++will[j];
                }
                else if (exp[i] < exp[j]) {
                    ++will[i];
                }
            }
        }
    }
    for (int i=0; i<N; ++i) {
        answer = max(answer, will[i]);
    }
    return answer;
}