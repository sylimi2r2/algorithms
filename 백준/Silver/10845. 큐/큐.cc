#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> queue;

    int N; cin >> N;
    string cmd;
    for(int i=0; i<N; i++) {
        cin >> cmd;
        if(cmd == "push") {
            int X; cin >> X;
            queue.push_back(X);
        }
        else if(cmd == "pop") {
            if(queue.size()) {
                cout << queue[0] << "\n";
                queue.erase(queue.begin());
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if(cmd == "size") {
            cout << queue.size() << "\n";
        }
        else if(cmd == "empty") {
            cout << (queue.size() ? 0 : 1) << "\n";
        }
        else if(cmd == "front") {
            cout << (queue.size() ? queue[0] : -1) << "\n";
        }
        else {
            cout << (queue.size() ? queue[queue.size()-1] : -1) << "\n";
        }
    }

}
