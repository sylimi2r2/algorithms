#include <iostream>
using namespace std;

int N;
int heights[51];
int cnt[51] = {0,};

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
    double height = (double(y2-y1)/(x2-x1))*(x3-x1) + y1;
    return y3 < height;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> heights[i];

    for(int i=1; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            bool flag = true;
            for(int k=i+1; k<j; k++) {
                if(!check(i, heights[i], j, heights[j], k, heights[k])) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }

    int sol = -1;
    for(int i=1; i<=N; i++)
        sol = max(sol, cnt[i]);

    cout << sol;
}
