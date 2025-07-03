#include <stdio.h>
#include <stdlib.h>

// Struct node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Hàm tạo node mới
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Hàm tính độ dài danh sách liên kết
int lengthNode(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Hàm chèn phần tử vào đầu danh sách
Node* insertHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Hàm chèn phần tử vào cuối danh sách
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    // Nếu danh sách đang rỗng
    if (head == NULL) return newNode;

    // Duyệt đến node cuối cùng
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Hàm chèn phần tử trong danh sách
Node* insertAt(Node* head, int data, int index) {
    // Kiểm tra vị trí hợp lệ
    if (index < 0 || index > lengthNode(head)) {
        printf("Index is not valid");
        return head;
    }

    // Chèn đầu
    if (index == 0) {
        return insertHead(head, data);
    }

    // Chèn cuối
    if (index == lengthNode(head)) {
        return insertEnd(head, data);
    }

    // Chèn ở vị trí giữa
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* newNode = createNode(data);
    Node* nextNode = current->next;

    current->next = newNode;   // Node trước trỏ đến node mới
    newNode->next = nextNode;  // Node mới trỏ đến node sau

    return head;
}

// In danh sách liên kết
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
}

int main() {
    // Khởi tạo danh sách
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    int value, position;
    printf("value: ");
    scanf("%d", &value);

    printf("position: ");
    scanf("%d", &position);

    position--; // Giảm vị trí

    head = insertAt(head, value, position);

    printList(head);

    return 0;
}