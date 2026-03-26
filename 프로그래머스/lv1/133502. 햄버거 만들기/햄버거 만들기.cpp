#include <string>
#include <vector>
// #include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    // stack<int> st;
    // st.push(0);
    vector<int> v = {0,};
    
    for (int i: ingredient) {
        if (i == 1 && v.back() == 123) {
            v.pop_back();
            ++answer;
        }
        else if (i == 2 && v.back() == 1) {
            v.back() = 12;
        }
        else if (i == 3 && v.back() == 12) {
            v.back() = 123;
        }
        else {
            v.push_back(i);
        }
        // if (i == 1 && st.top() == 123) {
        //     st.pop();
        //     ++answer;
        // }
        // else if (i == 2 && st.top() == 1) {
        //     st.pop();
        //     st.push(12);
        // }
        // else if (i == 3 && st.top() == 12) {
        //     st.pop();
        //     st.push(123);
        // }
        // else {
        //     st.push(i);
        // }
    }
    return answer;
}