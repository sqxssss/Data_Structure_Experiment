#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} LNode, *p;

void debugprint(LNode *p) {
    return;
    for (; p; p = p->next) printf("<%p: %d,%p> ", p, p->data, p->next);
    puts("");
}

LNode *CreateLinklist(int n) {
    LNode *head, *p, *q;
    int i;
    head = (LNode *) malloc(sizeof(LNode));
    head->next = NULL;
    p = head;
    q = p;//指针q始终指向链尾节点
    for (i = 1; i <= n; i++) {
        p = (LNode *) malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return head;
}

LNode *MergeLinklist(LNode *a, LNode *b, int m, int n) {
    LNode *k = a;
    LNode *p = a->next;
    LNode *q = b->next;
    LNode *C = k;
    while (p && q) {
        if (p->data <= q->data) {
            k->next = p;
            k->next->data = p->data;
            p = p->next;
            k = k->next;
        } else {
            k->next = q;
            k->next->data = q->data;
            q = q->next;
            k = k->next;
        }
    }
    k->next = p ? p : q;
    return C;
}

void print(LNode *p) {
    LNode *q;
    q = p->next;
    while (q != NULL) {
        printf("%d\n", q->data);
        q = q->next;
    }
}

int main() {
    int m, n;
    LNode *A, *B, *D;
    scanf("%d", &m);
    A = CreateLinklist(m);
    scanf("%d", &n);
    B = CreateLinklist(n);
    debugprint(A);
    debugprint(B);
    D = MergeLinklist(A, B, m, n);
    debugprint(D);
    print(D);
    return 0;
}

//
// Created by sqx08 on 2020/4/24.
//

