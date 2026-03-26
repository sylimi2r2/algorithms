#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct _node {
    char data;
    struct _node * left;
    struct _node * right;
} Node;

Node * makeNode(char data) {
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void linkLeft(Node * root, Node * sub) {
    if(root->left != nullptr)
        free(root->left);

    root->left = sub;
}

void linkRight(Node * root, Node * sub) {
    if(root->right != nullptr)
        free(root->right);

    root->right = sub;
}

void preOrder(Node * root) {
    if(root == nullptr)
        return;

    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node * root) {
    if(root == nullptr)
        return;

    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void postOrder(Node * root) {
    if(root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

Node * nodes[26];

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        nodes[i] = makeNode(char('A'+i));
    }

    for(int i=0; i<N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        if(left != '.') {
            linkLeft(nodes[root-'A'], nodes[left-'A']);
        }
        if(right != '.') {
            linkRight(nodes[root-'A'], nodes[right-'A']);
        }
    }

    preOrder(nodes[0]);
    cout << '\n';
    inOrder(nodes[0]);
    cout << '\n';
    postOrder(nodes[0]);

    for(int i=0; i<N; i++) {
        free(nodes[i]);
    }


}
