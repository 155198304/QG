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

// ����˫�������������������롢ɾ���ڵ㣩����������ʵ��

int main() {
    DListNode* head = createNode(0);
    // ���Ԫ��
    // ...
    // ��ӡ˫������
    printDList(head);
    return 0;
}