#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string, int> um;
    
    for (int i=0; i<cities.size(); ++i) {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), [](unsigned char c) {
            return tolower(c);
        });
        auto it = um.find(city);
        
        if (it == um.end()) {
            answer += 5;
            um.insert({city, i});
        } else {
            answer += 1;
            it->second = i;
        }
        
        if (um.size() > cacheSize) {
            string del;
            int MIN = 100001;
            
            for (auto c: um) {
                if (c.second < MIN) {
                    del = c.first;
                    MIN = c.second;
                }
            }
            
            um.erase(del);
        }
    }
    
    return answer;
}