#include <iostream>
using namespace std;

typedef struct _deque {
    int front;
    int back;
    int deque[20001];
} Deque;

void dequeInit(Deque * dq) {
    dq->front = 10000;
    dq->back = 10000;
}

int isEmpty(Deque * dq) {
    if(dq->front == dq->back)
        return 1;
    else
        return 0;
}

void push_front(Deque * dq, int data) {
    dq->deque[--dq->front] = data;
}

void push_back(Deque * dq, int data) {
    dq->deque[dq->back++] = data;
}

int pop_front(Deque * dq) {
    if(isEmpty(dq))
        return -1;

    return dq->deque[dq->front++];
}

int pop_back(Deque * dq) {
    if(isEmpty(dq))
        return -1;

    return dq->deque[--dq->back];
}

int size(Deque * dq) {
    return dq->back - dq->front;
}

int front(Deque * dq) {
    if(isEmpty(dq))
        return -1;

    return dq->deque[dq->front];
}

int back(Deque * dq) {
    if(isEmpty(dq))
        return -1;

    return dq->deque[dq->back-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Deque dq;
    dequeInit(&dq);

    int N;
    cin >> N;

    while(N--) {
        string cmd;
        cin >> cmd;

        if(cmd == "push_front") {
            int data;
            cin >> data;
            push_front(&dq, data);
        }
        else if(cmd == "push_back") {
            int data;
            cin >> data;
            push_back(&dq, data);
        }
        else if(cmd == "pop_front") {
            cout << pop_front(&dq) << '\n';
        }
        else if(cmd == "pop_back") {
            cout << pop_back(&dq) << '\n';
        }
        else if(cmd == "size") {
            cout << size(&dq) << '\n';
        }
        else if(cmd == "empty") {
            cout << isEmpty(&dq) << '\n';
        }
        else if(cmd == "front") {
            cout << front(&dq) << '\n';
        }
        else if(cmd == "back") {
            cout << back(&dq) << '\n';
        }
    }
}
