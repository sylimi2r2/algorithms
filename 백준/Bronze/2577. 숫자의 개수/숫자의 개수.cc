#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int often[10] = {0,};
    int A, B, C;
    cin >> A >> B >> C;

    int result = A*B*C;

    while(result) {
        often[result%10]++;
        result /= 10;
    }

    for(int i=0; i<10; i++) {
        cout << often[i] << endl;
    }
}
