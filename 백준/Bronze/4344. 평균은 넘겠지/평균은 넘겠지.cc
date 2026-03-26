#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(3);

    int C;
    cin >> C;
    while(C--) {
        int N;
        float sum = 0, students = 0;
        cin >> N;
        int scores[N];
        for(int i=0; i<N; i++) {
            cin >> scores[i];
            sum += scores[i];
        }
        float avg = sum / N;
        for(int i=0; i<N; i++) {
            if(scores[i] > avg)
                students++;
        }
        cout << students/N*100 << "%\n";
    }
}
