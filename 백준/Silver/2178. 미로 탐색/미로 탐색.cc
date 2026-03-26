#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> map;
int N, M;

void solution(int xPos, int yPos) {
    priority_queue<vector<int>> pq;
    vector<pair<int, int>> way = {{0,  1},
                                  {0,  -1},
                                  {1,  0},
                                  {-1, 0}};

    int MC = 0;
    int EC = (int) sqrt(pow(N, 2) + pow(M, 2));
    int TC = MC + EC;

    vector<int> firstNode = {-TC, -MC, xPos, yPos};
    pq.push(firstNode);

    while (!pq.empty()) {
        while (true) {
            TC = -pq.top()[0];
            MC = -pq.top()[1];
            xPos = pq.top()[2];
            yPos = pq.top()[3];
            pq.pop();
            if (map[xPos][yPos]) break;
        }
        map[xPos][yPos] = 0;
        if (xPos == N && yPos == M) break;
        for (int i = 0; i < 4; i++) {
            int nextX = xPos + way[i].first;
            int nextY = yPos + way[i].second;
            if (nextX >= 0 && nextX <= N && nextY >= 0 && nextY <= M && map[nextX][nextY]) {
                int nextMC = MC + 1;
                int nextEC = (int) sqrt(pow(N - nextX, 2) + pow(M - nextY, 2));
                int nextTC = nextMC + nextEC;
                vector<int> nextNode = {-nextTC, -nextMC, nextX, nextY};
                pq.push(nextNode);
            }
        }
    }
    cout << TC+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        vector<int> mapI;
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            mapI.push_back((int)(s[j] - '0'));
        }
        map.push_back(mapI);
    }

    N--;
    M--;

    solution(0,0);

}
