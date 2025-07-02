#include <stdio.h>
#include <stdlib.h>

//Struct note
typedef struct note {
    int data;              // Dữ liệu của node
    struct note *next;     // Con trỏ trỏ đến node tiếp theo
} note;

// Hàm tạo một node mới với giá trị cho trước
note* get(int value) {
    note* head = (note*)malloc(sizeof(note));  // Cấp phát bộ nhớ cho node mới
    head->data = value;                        // Gán giá trị cho trường data
    head->next = NULL;                         // Node mới chưa trỏ đến node nào khác
    return head;                               // Trả về con trỏ đến node mới
}

int main(void) {
    // Tạo node đầu với giá trị 10
    note* head = get(10);
    // Tạo các node tiếp theo và liên kết chúng lại
    head->next = get(20);
    head->next->next = get(30);
    head->next->next->next = get(40);
    head->next->next->next->next = get(50);

    return 0;
}