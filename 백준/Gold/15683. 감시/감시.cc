#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> cctv;
int map[8][8];
int N, M;
int sol = 0;
vector<int> type_two[2] = {{1, 3}, {2, 4}};
vector<int> type_three[4] = {{1, 2}, {2, 3}, {3, 4}, {4, 1}};
vector<int> type_four[4] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 1}, {4, 1, 2}};
/**
 * 1 : up
 * 2 : right
 * 3 : down
 * 4 : left
 */
void direction(int x, int y, int d) {
    switch(d) {
        case 1:
         for(int i=x-1; i>=0; i--) {
             if(map[i][y]==0)
                 map[i][y] = -1;
             else if(map[i][y]==-1)
                 continue;
             else if(map[i][y]==6)
                 break;
         }
            break;
        case 2:
            for(int i=y+1; i<M; i++) {
                if(map[x][i]==0)
                    map[x][i] = -1;
                else if(map[x][i]==-1)
                    continue;
                else if(map[x][i]==6)
                    break;
            }
            break;
        case 3:
            for(int i=x+1; i<N; i++) {
                if(map[i][y]==0)
                    map[i][y] = -1;
                else if(map[i][y]==-1)
                    continue;
                else if(map[i][y]==6)
                    break;
            }
            break;
        case 4:
            for(int i=y-1; i>=0; i--) {
                if(map[x][i]==0)
                    map[x][i] = -1;
                else if(map[x][i]==-1)
                    continue;
                else if(map[x][i]==6)
                    break;
            }
            break;
    }
}

void copy(int a[][8], int b[][8]) {
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            a[i][j] = b[i][j];
}

void dfs(int depth) {
    if(depth == cctv.size()) {
        int cnt = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] == 0)
                    cnt++;
            }
        }
        sol = min(sol, cnt);
        return;
    }

    int prev[8][8];
    copy(prev, map);

    int kind = map[cctv[depth].first][cctv[depth].second];
    switch (kind) {
        case 1:
            for(int i=1; i<=4; i++) {
                direction(cctv[depth].first, cctv[depth].second, i);
                dfs(depth+1);
                copy(map, prev);
            }
            break;
        case 2:
            for(vector<int> v : type_two) {
                for(int i=0; i<2; i++) {
                    direction(cctv[depth].first, cctv[depth].second, v[i]);
                }
                dfs(depth+1);
                copy(map, prev);
            }
            break;
        case 3:
            for(vector<int> v : type_three) {
                for(int i=0; i<2; i++) {
                    direction(cctv[depth].first, cctv[depth].second, v[i]);
                }
                dfs(depth+1);
                copy(map, prev);
            }
            break;
        case 4:
            for(vector<int> v : type_four) {
                for(int i=0; i<3; i++) {
                    direction(cctv[depth].first, cctv[depth].second, v[i]);
                }
                dfs(depth+1);
                copy(map, prev);
            }
            break;
        case 5:
            for(int i=1; i<=4; i++) {
                direction(cctv[depth].first, cctv[depth].second, i);
            }
            dfs(depth+1);
            break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0)
                sol++;
            if(map[i][j]!=0 && map[i][j]!=6)
                cctv.push_back({i, j});
        }




    dfs(0);

    cout << sol;
}
