#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string &a, string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

int main() {
    int N;
    cin >> N;
    vector<string> words;
    for (int i=0; i<N; ++i) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), compare);
    words.erase(unique(words.begin(), words.end()), words.end());

    for (string word: words) {
        cout << word << '\n';
    }
}
