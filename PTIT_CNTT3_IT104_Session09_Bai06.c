#include <stdio.h>
#include <stdlib.h>

//Struct note
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo node mới với giá trị cho trước
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// In toàn bộ danh sách theo dạng 1->2->3->NULL
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

// Xóa node đầu danh sách và trả về head mới
Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng, không thể xóa.\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Danh sách ban đầu:\n");
    printList(head);
    head = deleteHead(head);
    printf("Danh sách sau khi xóa phần tử đầu:\n");
    printList(head);

    return 0;
}