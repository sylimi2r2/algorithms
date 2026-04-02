#include <iostream>

using namespace std;

int deq[20001];
int head = 10000;
int tail = 10000;

int size() {
    return tail - head;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    while (N--) {
        string command;
        cin >> command;

        if (command == "pop_front") {
            cout << (size() ? deq[head++] : -1) << '\n';

            continue;
        }

        if (command == "pop_back") {
            cout << (size() ? deq[--tail] : -1) << '\n';

            continue;
        }

        if (command == "size") {
            cout << size() << '\n';

            continue;
        }

        if (command == "empty") {
            cout << (size() ? 0 : 1) << '\n';

            continue;
        }

        if (command == "front") {
            cout << (size() ? deq[head] : -1) << '\n';

            continue;
        }

        if (command == "back") {
            cout << (size() ? deq[tail - 1] : -1) << '\n';

            continue;
        }

        int X;
        cin >> X;

        if (command == "push_front") {
            deq[--head] = X;

            continue;
        }

        if (command == "push_back") {
            deq[tail++] = X;
        }
    }
}