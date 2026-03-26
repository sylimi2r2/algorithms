#include <iostream>
using namespace std;

int n;
bool num[246913];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i=2; i<=246912; i++)
        num[i] = true;

    for(int i=2; i<=246912; i++) {
        if(!num[i])
            continue;
        for(int j=2*i; j<=246912; j+=i)
            num[j] = false;
    }

    while(true) {
        cin >> n;

        if(n==0)
            break;

        int cnt = 0;

        for(int i=n+1; i<=2*n; i++)
            if(num[i])
                cnt++;

        cout << cnt << '\n';
    }
}