#include <iostream>
#include <map>
using namespace std;

struct TREE {
    map<string, TREE*> child;

    void print(int level) {
        for (auto next: child) {
            for (int i = 0; i < level; ++i) {
                cout << "--";
            }
            cout << next.first << '\n';
            next.second->print(level + 1);
        }
    }

    TREE* insert(string &name) {
        if (child.find(name) == child.end()) {
            child.insert({name, new TREE});
        }

        return child.find(name)->second;
    }
};

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    TREE t;
    cin >> N;
    while (N--) {
        int level;
        string temp;
        TREE *sT = &t;

        cin >> level;
        for (int i = 0; i < level; ++i) {
            cin >> temp;
            sT = sT->insert(temp);
        }
    }

    t.print(0);
}
