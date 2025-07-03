#include <stdio.h>
#include <stdlib.h>

// Struct note
typedef struct node {
    int data;              // Dữ liệu của node
    struct node *next;     // Con trỏ đến node kế tiếp
} node;

// Hàm tạo node mới với giá trị cho trước
node* get(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(void) {
    node* head = get(10);
    head->next = get(20);
    head->next->next = get(30);
    head->next->next->next = get(40);
    head->next->next->next->next = get(50);
    node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}