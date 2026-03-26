#include <iostream>
using namespace std;

int sol = 0;
int N, K;
int schedule[100];
int mT[100] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i=0; i<K; i++)
        cin >> schedule[i];

    for(int i=0; i<K; i++) {
        int task = schedule[i];
        bool isUsing = false;

        for(int j=0; j<N; j++) {
            if(mT[j] == task) {
                isUsing = true;
                break;
            }
        }

        if(isUsing)
            continue;

        else {
            int blank;
            for(blank=0; blank<N; blank++) {
                if(mT[blank] == 0)
                    break;
            }

            if(blank != N) {
                mT[blank] = task;
                continue;
            }

            else {
                int lP = 0;

                for(int j=0; j<N; j++) {
                    int distance = 1;
                    for(int k=i+1; k<K; k++) {
                        if(mT[j] == schedule[k]) {
                            break;
                        }
                        distance++;
                    }
                    if(lP < distance) {
                        lP = distance;
                        blank = j;
                    }
                }

                mT[blank] = task;
                sol++;
            }
        }
    }

    cout << sol;

}