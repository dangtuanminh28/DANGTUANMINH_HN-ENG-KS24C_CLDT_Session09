#include <stdio.h>
#include <stdlib.h>

// Struct note
typedef struct note {
    int data;              // Dữ liệu của node
    struct note *next;     // Con trỏ đến node kế tiếp
} note;

// Hàm tạo một node mới với giá trị cho trước
note* get(int value) {
    note* head = (note*)malloc(sizeof(note));
    head->data = value;
    head->next = NULL;
    return head;
}

// Hàm xóa node tại vị trí pos (từ 1)
note* dele(note* head, int pos) {
    if (head == NULL || pos <= 0) return head;

    if (pos == 1) { // Xóa node đầu
        note* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    note* temp = head;
    for (int i = 0; i < pos - 2; i++) {
        if (temp == NULL || temp->next == NULL) return head;
        temp = temp->next;
    }

    if (temp->next == NULL) return head;

    note* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

// Hàm in toàn bộ danh sách
void find(note* head) {
    note* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    // Tạo danh sách liên kết
    note* head = get(1);
    head->next = get(2);
    head->next->next = get(3);
    head->next->next->next = get(4);
    head->next->next->next->next = get(5);

    int pos;
    scanf("%d", &pos);       // Nhập vị trí cần xóa
    head = dele(head, pos);  // Xóa node tại vị trí đó
    find(head);              // In danh sách sau khi xóa

    return 0;
}