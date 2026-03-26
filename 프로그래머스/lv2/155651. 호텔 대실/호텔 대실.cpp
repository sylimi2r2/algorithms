#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int toInt(string str) {
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3, 2));
    return hour * 100 + min;
}

int cleaning(int out) {
    out += 10;
    if (out % 100 >= 60) {
        out += 40;
    }
    return out;
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    sort(book_time.begin(), book_time.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(cleaning(toInt(book_time[0][1])));
    for (int i=1; i<book_time.size(); ++i) {
        int in = toInt(book_time[i][0]);
        if (pq.top() <= in) {
            pq.pop();
        }
        pq.push(cleaning(toInt(book_time[i][1])));
        answer = max(answer, (int)pq.size());
    }
    return answer;
}