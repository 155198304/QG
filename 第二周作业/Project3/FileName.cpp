#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int is_empty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, void* new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

void* dequeue(Queue* q) {
    if (is_empty(q)) {
        return NULL; // 或者处理错误
    }

    Node* old_front = q->front;
    void* data = q->front->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(old_front);
    return data;
}

void destroy_queue(Queue* q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}

// 示例用法
int main() {
    Queue* q = create_queue();

    // 入队操作
    enqueue(q, (void*)1);
    enqueue(q, (void*)2);
    enqueue(q, (void*)3);

    // 出队操作
    int data;
    while (!is_empty(q)) {
        data = *(int*)dequeue(q);
        printf("%d ", data);
    }

    // 销毁队列
    destroy_queue(q);

    return 0;
}