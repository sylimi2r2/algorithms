#include <bits/stdc++.h>
using namespace std;

int count(int n) {
    int cnt = 0;
    for(int i=1; i*i<=n; i++) {
        if(n%i) continue;
        if(i*i == n) cnt += 1;
        else cnt += 2;
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int acc = 0;
    for(int n=1; n<=number; n++) {
        int cnt = count(n);
        acc += (cnt > limit ? power : cnt);
    }
    return acc;
}