#include <stdio.h>
#include <stdlib.h>

// Struct note
typedef struct note {
    int data;              // Dữ liệu của node
    struct note *next;     // Con trỏ đến node kế tiếp
} note;

// Hàm tạo node mới với giá trị cho trước
note* get(int value) {
    note* newNode = (note*)malloc(sizeof(note));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(void) {
    note* head = get(10);
    head->next = get(20);
    head->next->next = get(30);
    head->next->next->next = get(40);
    head->next->next->next->next = get(50);
    note* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}