#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        deque<int> dq;
        bool reverse = false;
        bool error = false;
        string cmd, input;
        int n;
        cin >> cmd >> n >> input;

        stringstream ss(input.substr(1,input.length()-2));
        string token;
        while(getline(ss, token, ',')) {
            dq.push_back(stoi(token));
        }

        for(int i=0; i<cmd.length(); i++) {
            switch(cmd[i]) {
                case 'R': {
                    reverse = !reverse;
                    break;
                }
                case 'D': {
                    if(dq.empty()) {
                        error = true;
                        break;
                    }
                    if(reverse)
                        dq.pop_back();
                    else
                        dq.pop_front();
                    break;
                }
            }
        }

        if(!error) {
            cout << "[";

            if(!reverse && !dq.empty()) {
                for(int i=0; i<dq.size()-1; i++) {
                    cout << dq[i] << ',';
                }
                cout << dq[dq.size()-1];
            }
            else if(reverse && !dq.empty()) {
                for(int i=dq.size()-1; i>0; i--) {
                    cout << dq[i] << ',';
                }
                cout << dq[0];
            }
            cout << "]\n";
        }
        else {
            cout << "error\n";
        }
    }
}
