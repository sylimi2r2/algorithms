#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<bool> visited(201, false);
    int n = numbers.size();
    for (int i=0; i<n-1; ++i) {
        for (int j=i+1; j<n; ++j) {
            int input = numbers[i] + numbers[j];
            if (!visited[input]) {
                answer.push_back(input);
                visited[input] = true;    
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}