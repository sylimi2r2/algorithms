#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int alphabets[26] = {0, };
int N;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sol = 0;

    cin >> N;
    for(int i=0; i<N; i++) {
        string input;
        cin >> input;

        int len = input.length();
        for(int j=0; j<len; j++) {
            alphabets[input[j]-'A'] += pow(10, len-j-1);
        }
    }

    sort(alphabets, alphabets+26, comp);

    for(int i=0; i<10; i++) {
        sol += alphabets[i] * (9-i);
    }

    cout << sol;
}
