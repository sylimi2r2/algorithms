#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, W, H;
    cin >> N >> W >> H;

    int diagonal = W*W + H*H;
    while(N--) {
        int input;
        cin >> input;
        if(input*input <= diagonal)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
}