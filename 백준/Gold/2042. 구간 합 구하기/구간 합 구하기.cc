#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M, K;
long long n;
int a, b;
long long c;
vector<long long> arr;
vector<long long> segTree;

long long initTree(int node, int start, int end) {
    if (start == end)
        return segTree[node] = arr[start];

    int mid = (start + end) / 2;
    return segTree[node] = initTree(node * 2, start, mid) + initTree(node * 2 + 1, mid + 1, end);;
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && right >= end)
        return segTree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void updateTree(int node, int start, int end, int idx, long long diff) {
    if (idx < start || idx > end)
        return;

    segTree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        updateTree(node * 2, start, mid, idx, diff);
        updateTree(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> n;
        arr.emplace_back(n);
    }
    int height = (int) ceil(log2(N));
    int size = (1 << (height + 1));
    segTree.resize(size);
    initTree(1, 0, N - 1);

    for (int i = 0; i < M + K; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            long long diff = c - arr[b - 1];
            arr[b-1] = c;
            updateTree(1, 0, N - 1, b - 1, diff);
        }
        else {
            cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}
