#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> trees;

long long cutTree(long long height) {
    int size = trees.size();
    long long sum = 0;
    for(int i=0; i<size; i++) {
        int cut = trees[i]-height;
        if(cut > 0)
            sum += cut;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    long long left = 0, right = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int tree;
        cin >> tree;
        if(tree > right) right = tree;
        trees.push_back(tree);
    }

    long long mid;
    long long sol=0;
    while(left <= right) {
        mid = (left+right)/2;
        if(cutTree(mid) >= M) {
            left = mid+1;
            if(mid > sol) sol = mid;
        }
        else {
            right = mid-1;
        }
    }
    cout << sol;
}
