#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Date
{
public:
    int year;
    int month;
    int day;
    
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

int dtoi(Date date) {
    return date.year * 10000 + date.month * 100 + date.day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // today 숫자화
    Date cur = Date(stoi(today.substr(0, 4)), stoi(today.substr(5, 2)), stoi(today.substr(8, 2)));
    
    // terms 정리
    unordered_map<char, int> tm;
    for (string t: terms) {
        tm.insert(make_pair(t[0], stoi(t.substr(2))));
    }
    
    // privacies 정리
    vector<pair<char, Date>> pv;
    for (string p: privacies) {
        
        pv.push_back(make_pair(p[11], Date(stoi(p.substr(0, 4)), 
                                            stoi(p.substr(5, 2)), 
                                            stoi(p.substr(8, 2)))));
    }
                    
    for (int i=0; i<pv.size(); ++i) {
        auto p = pv[i];
        int plus = tm[p.first];
        Date limit = p.second;
        limit.month += plus;
        while (limit.month > 12) {
            limit.month -= 12;
            limit.year++;
        }
        if (--limit.day == 0) {
            limit.day = 28;
            if (--limit.month == 0) {
                limit.month = 12;
                --limit.year;
            }
        }
        if (dtoi(cur) > dtoi(limit)) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}