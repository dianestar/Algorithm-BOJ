#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* makeTree(Node* root, int num) {
    if (root == NULL) {
        root = new Node();
        root->key = num;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        if (num < root->key) { root->left = makeTree(root->left, num); }
        else { root->right = makeTree(root->right, num); }
    }
    return root;
}

void postorder(Node *root) {
    if (root->left != NULL) { postorder(root->left); }
    if (root->right != NULL) { postorder(root->right); }
    printf("%d\n", root->key);
}

int main() {
    int num;
    Node *root = NULL;

    while (scanf("%d", &num) != EOF) {
        root = makeTree(root, num);
    }

    postorder(root);

    return 0;
}