#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string &a, const string &b) {
    return a+b > b+a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    vector<string> list;
    cin >> N;
    for(int i=0; i<N; i++) {
        string input;
        cin >> input;
        list.push_back(input);
    }
    sort(list.begin(), list.end(), comp);

    if(list[0] != "0") {
        for(string s : list)
            cout << s;
    }
    else
        cout << "0";
}
