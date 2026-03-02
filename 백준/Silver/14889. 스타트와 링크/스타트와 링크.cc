#include <iostream>
using namespace std;

int N;
int S[20][20];
bool visited[20] = {0,};
int sol = 100000;

void dfs(int num, int index) {
    if(num == N/2) {
        int start = 0, link = 0;

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(visited[i] && visited[j])
                    start += S[i][j];
                else if(!visited[i] && !visited[j])
                    link += S[i][j];
            }
        }

        sol = min(sol, abs(start-link));

        return;
    }

    for(int i=index; i<N; i++) {
        visited[i] = true;
        dfs(num+1, i+1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> S[i][j];
        }
    }

    dfs(0, 0);

    cout << sol;
}
