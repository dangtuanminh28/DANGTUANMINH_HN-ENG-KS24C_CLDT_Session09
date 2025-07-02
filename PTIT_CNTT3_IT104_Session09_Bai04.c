#include <stdio.h>
#include <stdlib.h>

// Struct node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Tạo một node mới với giá trị cho trước
Node* makeNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Tính và in độ dài của danh sách
void countLength(Node* headRef) {
    int count = 0;
    Node* ptr = headRef;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    printf("Danh sach lien ket gom %d phan tu\n", count);
}

int main() {
    Node* head = makeNode(1);
    head->next = makeNode(2);
    head->next->next = makeNode(3);
    head->next->next->next = makeNode(4);
    head->next->next->next->next = makeNode(5);

    countLength(head);

    return 0;
}