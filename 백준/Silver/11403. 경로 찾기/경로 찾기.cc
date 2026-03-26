#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> map;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        vector<int> rowI;
        for(int j=0; j<N; j++) {
            int input;
            cin >> input;
            rowI.push_back(input);
        }
        map.push_back(rowI);
    }

    for(int k=0; k<N; k++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][k] && map[k][j])
                    map[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
