#include <stdio.h>
#include <stdlib.h>

//Struct note
typedef struct note {
    int data;
    struct note *next;
} note;

// Hàm tạo node mới với giá trị cho trước
note* get(int value) {
    note* head = (note*)malloc(sizeof(note));
    head->data = value;
    head->next = NULL;
    return head;
}

// Hàm chèn node mới danh sách
note* insertAtHead(note* head, int value) {
    note* newNode = get(value);
    newNode->next = head;
    return newNode;
}

// Hàm in toàn bộ danh sách
note* find(note* head) {
    note* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    note* head = get(10);
    head->next = get(20);
    head->next->next = get(30);
    head->next->next->next = get(40);
    head->next->next->next->next = get(50);

    head = insertAtHead(head, 5);
    find(head);

    return 0;
}