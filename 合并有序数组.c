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
//#include<stdio.h>
//#include<stdlib.h>
//
////归并作用是将两个序列合并 L = 左边起始位置,R = 右边起始位置 RightEnd = 右边终点位置
//void Merge(int A[],int TmpA[],int L,int R,int RightEnd)
//{
//	int LeftEnd = R -1;         //左边终点位置 左右两列挨着
//	int Tmp = L;                //存放结果初始位置
//	int NumElements = RightEnd - L + 1;       //存放元素总个数
//	while(L <= LeftEnd && R<= RightEnd)       //当左右两边都存在元素时比较大小将小的哪一个存入数组Tmp中
//	{
//		if(A[L] <A[R] )        //如果左边的值小则将左边的元素存入数组中
//			TmpA[Tmp++] = A[L++];
//		else                   //反之
//			TmpA[Tmp++] = A[R++];
//	}
//	while(L <= LeftEnd)         //如果左边的数组长一点则将后面的直接存入数组
//		TmpA[Tmp++] = A[L++];
//	while(R <= RightEnd)
//		TmpA[Tmp++] = A[R++];  //反之
//	for(int i = 0; i < NumElements;i++,RightEnd --)  //用NumElem来控制赋值的次数
//		A[RightEnd] = TmpA[RightEnd];
//}
//
//void main()
//{
//	int a[11] = {1,3,5,7,9,2,4,6,8,10,20};
//	int b[11] = {0};
//	Merge(a,b,0,5,9);
//	for(int i=0;i<11;i++)
//	{
//		printf("%d\n",a[i]);
//	}
//	getchar();
//}
