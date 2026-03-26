#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin >> N >> M;
    int card[N];
    for(int i=0; i<N; i++) {
        cin >> card[i];
    }
    sort(card, card+N);

    int max = 0;
    int sum = 0;

    for(int i=N-1; i>1; i--) {
        for(int j=i-1; j>0; j--) {
            for(int k=j-1; k>-1; k--) {
                sum = card[i] + card[j] + card[k];
                if(sum == M) {
                    max = sum;
                    goto print;
                }
                else if(sum < M && sum > max) max = sum;
            }
        }
    }

    print:
    cout << max;

}
