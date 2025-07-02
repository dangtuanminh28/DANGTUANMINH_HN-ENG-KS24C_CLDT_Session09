#include <stdio.h>
#include <stdlib.h>

// Định nghĩa struct Node để biểu diễn 1 phần tử trong danh sách liên kết
typedef struct Node {
    int data;             // Dữ liệu của node
    struct Node *next;    // Con trỏ trỏ đến node kế tiếp
} Node;

// Hàm tạo node mới với giá trị cho trước
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm tính độ dài của danh sách liên kết
int lengthNode(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Hàm tìm kiếm 1 giá trị trong danh sách
void findNode(Node* head, int target) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == target) {
            printf("True\n");
            return;
        }
        temp = temp->next;
    }

    printf("False\n");
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int target;
    printf("Nhap gia tri Node can tim: ");
    scanf("%d", &target);
    findNode(head, target);
    return 0;
}