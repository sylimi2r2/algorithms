#include <iostream>
#include <vector>
using namespace std;

vector<int> nodes;

void postOrder(int start, int end) {
    if(start >= end)
        return;
    if(start == end-1) {
        cout << nodes[start] << '\n';
        return;
    }

    int i = start + 1;
    while(i != end) {
        if(nodes[i] > nodes[start])
            break;
        i++;
    }

    postOrder(start+1, i);
    postOrder(i, end);
    cout << nodes[start] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while(cin >> n) {
        nodes.push_back(n);
    }
    postOrder(0, nodes.size());
}