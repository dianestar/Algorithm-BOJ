#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    int N, K;

    Node *headNode = NULL;
    Node *tailNode = NULL;
    Node *newNode;

    scanf("%d %d", &N, &K);

    for (int i=1; i<=N; i++) {
        newNode = new Node;
        newNode->data = i;
        newNode->next = NULL;

        if (headNode == NULL) {
            headNode = tailNode = newNode;
        }
        else {
            tailNode->next = newNode;
            tailNode = newNode;
        }
    }
    tailNode->next = headNode;

    printf("<"); 

    Node *prevNode = tailNode;
    Node *currNode = headNode;

    for (int i=0; i<N; i++) {
        for (int j=0; j<K-1; j++) {
            prevNode = prevNode->next;
            currNode = currNode->next;
        }

        if (i != N-1) { printf("%d, ", currNode->data); }
        else { printf("%d", currNode->data); }

        prevNode->next = currNode->next;
        delete currNode;
        currNode = prevNode->next;
    }
    printf(">");

    return 0;
}