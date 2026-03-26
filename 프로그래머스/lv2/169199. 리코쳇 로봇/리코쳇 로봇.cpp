#include <string>
#include <vector>
#include <queue>

using namespace std;
using Coord = pair<int,int>;

int bfs(const Coord start, const Coord end, const vector<string>& grid)
{
    const int n = grid.size();
    const int m = grid[0].size();
    const vector<Coord> offset{Coord{1,0},Coord{-1,0},Coord{0,1},Coord{0,-1}};

    queue<pair<Coord,int>> q;
    q.emplace(start,0);

    vector<vector<bool>> visited(n,vector<bool>(m,false));

    while(!q.empty())
    {
        const int i = q.front().first.first;
        const int j = q.front().first.second;
        const int distCur = q.front().second;        
        q.pop();

        if(i == end.first && j == end.second)
        {
            return distCur;
        }

        for(const auto& o : offset)
        {
            int ii = i;
            int jj = j;            
            while(true)
            {        
                ii += o.first;
                jj += o.second;
                if(ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] != 'D')
                {
                    continue;
                }
                else
                {
                    ii -= o.first;
                    jj -= o.second;
                    break;
                }
            }

            if(!visited[ii][jj])
            {
                visited[ii][jj] = true;
                q.emplace(Coord{ii,jj},distCur+1);
            }
        }
    }

    return -1;
}

int solution(vector<string> board) {
    const int n = board.size();
    const int m = board[0].size();
    Coord start;
    Coord end;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j] == 'R')
            {
                start = {i,j};
            }
            if(board[i][j] == 'G')
            {
                end = {i,j};
            }
        }
    }
    int answer = bfs(start,end,board);
    return answer;
}
