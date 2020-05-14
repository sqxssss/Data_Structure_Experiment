#include <stdio.h>
#include <stdlib.h>

typedef struct OLNode {
    int r, c, v;
    struct OLNode *right, *down;
} Node, *LNode;

typedef struct {
    LNode *Rhead, *Chead;
    int mu, nu, tu; //行数 列数 非零元的个数
} Cross, *LCross;

void CreateCrossList(LCross M) {
    int i;
    LNode p, temp;

    M->Rhead = (LNode *) malloc((M->mu + 1) * sizeof(LNode));
    M->Chead = (LNode *) malloc((M->nu + 1) * sizeof(LNode));

    for (i = 1; i <= M->mu; i++) {
        M->Rhead[i] = NULL;
    }
    if (M->tu != 0) {
        for (i = 1; i <= M->tu; i++) {
            p = (LNode) malloc(sizeof(Node));
            scanf("%d %d %d", &p->r, &p->c, &p->v);
            if (M->Rhead[p->r] == NULL) {
                p->right = NULL;
                M->Rhead[p->r] = p;
            } else {
                for (temp = M->Rhead[p->r];; temp = temp->right) {
                    if (temp->right == NULL) {
                        temp->right = p;
                        p->right = NULL;
                        break;
                    } else if (temp->c < p->c && temp->right->c > p->c) {
                        p->right = temp->right;
                        temp->right = p;
                        break;
                    } else if (temp == M->Rhead[p->r] && temp->c > p->c) {
                        p->right = temp;
                        temp = p;
                        break;
                    }
                }
            }
        }
    }
}

/*void CreateCrossList(LCross M)
{
    int k;
    LNode p,q;
    M->Rhead = (LNode *)malloc(((M->mu)+1) * sizeof(LNode));
    M->Chead = (LNode *)malloc(((M->nu)+1) * sizeof(LNode));
    for(k=1;k<=M->mu;k++)
        M->Rhead[k]=NULL;
    for(k=1;k<=M->nu;k++)
        M->Chead[k]=NULL;
    if(M->tu != 0)
    {
        for(k=1;k<=M->tu;k++)
        {
            p = (LNode)malloc(sizeof(Node));
            scanf("%d%d%d",&p->r,&p->c,&p->v);
            if(M->Rhead[p->r]==NULL || M->Rhead[p->r]->c>p->c)
            {
                p->right=NULL;
                M->Rhead[p->r]=p;
            }    //if is the first data
            else
            {
                for(q=M->Rhead[p->r];q->right&&q->right->c < p->c;q=q->right);
                p->right=q->right;
                q->right=p;
            }
            if(M->Chead[p->c]==NULL || M->Chead[p->c]->r>p->r)
            {
                p->down=M->Chead[p->c];
                M->Chead[p->c]=p;
            }
            else
            {
                for(q=M->Chead[p->c];q->down && q->down->r<p->r;q=q->down);
                p->down=q->down;
                q->down=p;
            }
        }
    }
}*/

void PlusCrossList(LCross M1, LCross M2) {
    int i;
    LNode p, temp1, temp2;
    for (i = 1; i <= M1->mu; i++) {
        if (M2->Rhead[i] == NULL) continue;
        else {
            if (M1->Rhead[i] == NULL) {

                p = (LNode) malloc(sizeof(Node));
                p->c = M2->Rhead[i]->c;
                p->r = M2->Rhead[i]->r;
                p->v = M2->Rhead[i]->v;
                M1->Rhead[i] = p;
                p->right = NULL;
                M2->Rhead[i] = M2->Rhead[i]->right;

            }
            if (M2->Rhead[i] == NULL)continue;
            for (temp1 = M2->Rhead[i];; temp1 = temp1->right) {
                for (temp2 = M1->Rhead[i];; temp2 = temp2->right) {
                    if (temp2->c == temp1->c) {
                        temp2->v += temp1->v;
                        break;
                    } else if (temp2 == M1->Rhead[i] && temp1->c < temp2->c) {
                        p = (LNode) malloc(sizeof(Node));
                        p->c = temp1->c;
                        p->r = temp1->r;
                        p->v = temp1->v;
                        p->right = temp2->right;
                        p->right = temp2;
                        M1->Rhead[i] = p;
                        break;
                    } else if ((temp2->right == NULL || temp2->right->c > temp1->c) && temp1->c > temp2->c) {
                        p = (LNode) malloc(sizeof(Node));
                        p->c = temp1->c;
                        p->r = temp1->r;
                        p->v = temp1->v;
                        p->right = temp2->right;
                        temp2->right = p;
                        break;
                    }

                }
                if (temp1->right == NULL) break;
            }
        }
    }
}

void PrintCrossList(LCross M) {
    int i;
    LNode p;
    for (i = 1; i <= M->mu; i++) {
        p = M->Rhead[i];
        while (p != NULL) {
            printf("%d %d %d\n", p->r, p->c, p->v);
            p = p->right;
        }
    }
}

int main() {

    LCross M1 = (LCross) malloc(sizeof(Cross));
    LCross M2 = (LCross) malloc(sizeof(Cross));
    scanf("%d%d%d%d", &M1->mu, &M1->nu, &M1->tu, &M2->tu);
    M2->mu = M1->mu;
    M2->nu = M1->nu;
    CreateCrossList(M1);
    CreateCrossList(M2);
    PlusCrossList(M1, M2);
    PrintCrossList(M1);
    return 0;
}//
// Created by sqx08 on 2020/5/14.
//

