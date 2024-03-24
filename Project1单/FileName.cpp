#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {
    int value;
    struct DListNode* prev;
    struct DListNode* next;
} DListNode;

DListNode* createNode(int value) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printDList(DListNode* head) {
    DListNode* current = head;
    while (current != NULL) {
        printf("[%d] -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// 其他双向链表操作函数（如插入、删除节点）可以在这里实现

int main() {
    DListNode* head = createNode(0);
    // 添加元素
    // ...
    // 打印双向链表
    printDList(head);
    return 0;
}