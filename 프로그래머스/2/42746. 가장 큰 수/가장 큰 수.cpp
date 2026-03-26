#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";     
    vector<string> n;
    for(int nums : numbers)
        n.push_back(to_string(nums));
    sort(n.begin(), n.end(), comp);
    if(n[0] == "0")
        return "0";
    for(string it : n)
        answer += it;
    return answer;
}