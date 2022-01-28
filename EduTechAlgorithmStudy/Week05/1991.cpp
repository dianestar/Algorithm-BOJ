#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left = NULL;
    Node *right = NULL;
};

void preorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printf("%c", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%c", node->data);
    inorder(node->right);
}


void postorder(Node *node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%c", node->data);
}

int main() {
    int N;
    scanf("%d", &N);

    Node *tree = new Node[N];
    char parent, left, right;
    for (int i=0; i<N; i++) {
        scanf(" %c %c %c", &parent, &left, &right);
        tree[parent-'A'].data = parent;
        if (left != '.') {
            tree[parent-'A'].left = &tree[left-'A'];
        }
        if (right != '.') {
            tree[parent-'A'].right = &tree[right-'A'];
        }
    }

    Node *root = &tree[0];
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}