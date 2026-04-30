#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Group {
    int dia;
    int iron;
    int stone;
};

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int p = picks[0] + picks[1] + picks[2];
    int limit = min((int)minerals.size(), p * 5);
    
    vector<Group> groups;
    
    for (int i=0; i<limit; i+=5) {
        Group g = {0, 0, 0};
        
        for (int j=i; j<i+5 && j<limit; ++j) {
            switch (minerals[j][0]) {
                case 'd': {
                    ++g.dia;
                    break;
                }
                case 'i': {
                    ++g.iron;
                    break;
                }
                default: {
                    ++g.stone;
                    break;
                }
            }
        }
        
        groups.push_back(g);
    }
    
    sort(groups.begin(), groups.end(), [](const Group& a, const Group& b) {
        if (a.dia != b.dia)
            return a.dia > b.dia;
        if (a.iron != b.iron)
            return a.iron > b.iron;
        return a.stone > b.stone;
    });
    
    for (auto& g: groups) {
        if (picks[0] > 0) {
            answer += g.dia + g.iron + g.stone;
            --picks[0];
        } else if (picks[1] > 0) {
            answer += g.dia * 5 + g.iron + g.stone;
            --picks[1];
        } else {
            answer += g.dia * 25 + g.iron * 5 + g.stone;
            --picks[2];
        }
    }
    
    return answer;
}