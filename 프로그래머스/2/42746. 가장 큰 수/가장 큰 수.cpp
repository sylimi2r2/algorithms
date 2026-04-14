#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> numString;
    
    for (int& num: numbers) {
        numString.push_back(to_string(num));
    }
    
    sort(numString.begin(), numString.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    if (numString[0] == "0")
        return "0";
    
    for (string& nS: numString) {
        answer += nS;
    }
    
    return answer;
}