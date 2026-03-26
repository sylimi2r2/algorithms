#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, P, V;

    int i=1;
    while(true) {
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0)
            break;

        int cnt = 0;
        while(V>0) {
            if(V>= L)
                cnt += L;
            else
                cnt += V;
            V -= P;
        }
        cout << "Case " << i++ << ": " << cnt << '\n';
    }
}
