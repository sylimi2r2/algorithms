#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string number;
    cin >> N >> number;

    int sum = 0;
    for(int i=0; i<N; i++) {
        sum += number[i] - '0';
    }
    cout << sum;
}
