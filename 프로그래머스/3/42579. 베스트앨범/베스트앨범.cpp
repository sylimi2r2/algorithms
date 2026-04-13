#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genreMap;
    vector<pair<int, int>> genrePlays;
    vector<vector<pair<int, int>>> albums;
    
    int idx = 0;
    for (int i=0; i<genres.size(); ++i) {
        auto it = genreMap.find(genres[i]);
        
        if (it == genreMap.end()) {
            genreMap.insert({genres[i], idx});
            genrePlays.push_back({-plays[i], idx});
            albums.push_back({{-plays[i], i}});
            ++idx;
        } else {
            int g = it->second;
            genrePlays[g].first -= plays[i];
            albums[g].push_back({-plays[i], i});
        }
    }
    
    sort(genrePlays.begin(), genrePlays.end());
    for (int i=0; i<genrePlays.size(); ++i) {
        int g = genrePlays[i].second;
        sort(albums[g].begin(), albums[g].end());
        
        answer.push_back(albums[g][0].second);
        if (albums[g].size() > 1) {
            answer.push_back(albums[g][1].second);
        }
    }
    
    return answer;
}