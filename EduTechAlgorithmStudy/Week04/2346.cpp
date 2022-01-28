#include <iostream>
using namespace std;

struct Node {
    int index;
    int data;
    Node *prev;
    Node *next;
};

int main() {
    int N, num;

    Node *headNode = NULL;
    Node *tailNode = NULL;
    Node *newNode;

    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &num);

        newNode = new Node;
        newNode->index = i;
        newNode->data = num;
        newNode->next = NULL;
        if (headNode == NULL) {
            headNode = tailNode = newNode;
        }
        else {
            newNode->prev = tailNode;
            tailNode->next = newNode;
            tailNode = newNode;
        }
    }
    headNode->prev = tailNode;
    tailNode->next = headNode;

    Node *currNode = headNode;
    Node *prevNode, *nextNode;
    int temp;

    printf("%d ", currNode->index);
    for (int i=1; i<N; i++) {
        temp = currNode->data;

        prevNode = currNode->prev;
        nextNode = currNode->next;
        prevNode->next = currNode->next;
        nextNode->prev = currNode->prev;
        delete currNode; 
        currNode = nextNode;

        if (temp > 0) {
            for (int j=0; j<temp-1; j++) {
                currNode = currNode->next;
            }
        }
        else {
            for (int j=temp; j<0; j++) {
                currNode = currNode->prev;
            }
        }
        
        printf("%d ", currNode->index);
    }

    return 0;
}