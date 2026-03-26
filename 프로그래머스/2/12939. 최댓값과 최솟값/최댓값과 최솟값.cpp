#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    
    stringstream ss(s);
    string word;
    while(getline(ss, word, ' ')) {
        nums.push_back(stoi(word));
    }
    
    int MAX = nums[0], MIN = nums[0];
    
    for(int num : nums) {
        MAX = (num > MAX) ? num : MAX;
        MIN = (num < MIN) ? num : MIN;
    }
    
    answer = to_string(MIN) + ' ' + to_string(MAX);
    return answer;
}