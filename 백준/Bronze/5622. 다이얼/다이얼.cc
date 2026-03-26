#include <iostream>
using namespace std;

int dial[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6,
                7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10,
                10, 10, 10};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string word;
  int sol = 0;
  cin >> word;

  for(int i=0; i<word.length(); i++)
    sol += dial[word[i]-'A'];

  cout << sol;
}
