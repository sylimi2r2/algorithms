#include <iostream>
using namespace std;

int matrix[1025][1025] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            matrix[i][j] += matrix[i][j-1];
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            matrix[i][j] += matrix[i-1][j];
        }
    }

    while(M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (matrix[x2][y2]-matrix[x1-1][y2]-matrix[x2][y1-1]+matrix[x1-1][y1-1]) << '\n';
    }
}
