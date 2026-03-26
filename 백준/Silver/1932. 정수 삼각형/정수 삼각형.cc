#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int triangle[501][501] = {0, };
    int N, sol = 0;
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            cin >> triangle[i][j];
            if(j!=1 && j!=i)
                triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
            else if(j == 1)
                triangle[i][j] += triangle[i-1][j];
            else
                triangle[i][j] += triangle[i-1][j-1];
        }
    }

    for(int i=1; i<=N; i++) {
        sol = max(sol, triangle[N][i]);
    }

    cout << sol;

}
