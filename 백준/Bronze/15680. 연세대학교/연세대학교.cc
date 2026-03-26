#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string name = "YONSEI";
    string slogan = "Leading the Way to the Future";

    int N;
    cin >> N;

    cout << (N ? slogan : name);
}