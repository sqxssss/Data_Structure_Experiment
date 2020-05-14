#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int r;
    int c;
    int v;
} node;

typedef struct {
    int cnt1;
    int cnt2;
    node matrix1[1000];
    node matrix2[1000];
} matrix;

void init(matrix *p) {
    int m, n, t1, t2;
    int x, y, z, i = 0;
    scanf("%d%d%d%d", &m, &n, &t1, &t2);
    p->cnt1 = t1;
    p->cnt2 = t2;
    while (1) {
        scanf("%d%d%d", &x, &y, &z);
        p->matrix1[i].r = x;
        p->matrix1[i].c = y;
        p->matrix1[i].v = z;
        i++;
        if (i == t1)break;
    }
    i = 0;
    while (1) {
        scanf("%d%d%d", &x, &y, &z);
        p->matrix2[i].r = x;
        p->matrix2[i].c = y;
        p->matrix2[i].v = z;
        i++;
        if (i == t2)break;
    }
}

void plus(matrix *p) {
    int flag, tmp;
    int i = 0, j = 0, k = p->cnt1 - 1;
    for (i = 0; i < p->cnt2; i++) {
        flag = 1;
        for (j = 0; j < p->cnt1; j++) {
            if (p->matrix1[j].r == p->matrix2[i].r && p->matrix1[j].c == p->matrix2[i].c) {
                p->matrix1[j].v += p->matrix2[i].v;
                flag = 0;
                break;
            } //if is the same r & c,plus
        }
        if (flag) {
            p->matrix1[++k].r = p->matrix2[i].r;
            p->matrix1[k].c = p->matrix2[i].c;
            p->matrix1[k].v = p->matrix2[i].v;
        }   //else , append
    }
    p->cnt1 = k + 1;
    for (i = 0; i < k; i++)
        for (j = i; j < k + 1; j++) {
            if (p->matrix1[i].r > p->matrix1[j].r) {
                tmp = p->matrix1[i].r;
                p->matrix1[i].r = p->matrix1[j].r;
                p->matrix1[j].r = tmp;
                tmp = p->matrix1[i].c;
                p->matrix1[i].c = p->matrix1[j].c;
                p->matrix1[j].c = tmp;
                tmp = p->matrix1[i].v;
                p->matrix1[i].v = p->matrix1[j].v;
                p->matrix1[j].v = tmp;
            }
        }
    for (i = 0; i < k; i++)
        for (j = i; j < k + 1; j++) {
            if (p->matrix1[i].r == p->matrix1[j].r && p->matrix1[i].c > p->matrix1[j].c) {
                tmp = p->matrix1[i].c;
                p->matrix1[i].c = p->matrix1[j].c;
                p->matrix1[j].c = tmp;
                tmp = p->matrix1[i].v;
                p->matrix1[i].v = p->matrix1[j].v;
                p->matrix1[j].v = tmp;
            }
        }
}

void output(matrix *p) {
    int tmp = 0;
    while ((p->cnt1)--) {
        printf("\n%d %d %d", p->matrix1[tmp].r, p->matrix1[tmp].c, p->matrix1[tmp].v);
        tmp++;
    }
}

int main() {
    matrix *p = (matrix *) malloc(sizeof(matrix));
    init(p);
    plus(p);
    output(p);
    return 0;
}//
// Created by sqx08 on 2020/5/14.
//

