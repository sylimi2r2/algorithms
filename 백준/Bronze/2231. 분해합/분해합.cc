#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool flag = false;
    string N; cin >> N;
    int num = stoi(N);
    int lowBound = num - (N[0]-'0') - 9*(N.length()-1);

    for(int i=lowBound; i<num; i++) {
        int sum = i;
        int tmp = i;

        while(tmp>0) {
            sum += tmp % 10;
            tmp /= 10;
        }

        if(sum==num) {
            cout << i;
            flag = true;
            break;
        }
    }

    if(!flag) cout << "0";
}
