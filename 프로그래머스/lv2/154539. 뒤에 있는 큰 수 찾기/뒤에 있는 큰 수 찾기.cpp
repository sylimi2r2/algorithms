#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> st;
    for (int i=0; i<numbers.size(); ++i) {
        while (!st.empty()) {
            if (st.top().second < numbers[i]) {
                answer[st.top().first] = numbers[i];
                st.pop();
            }
            else {
                break;
            }
        }
        st.push({i, numbers[i]});
    }
    return answer;
}