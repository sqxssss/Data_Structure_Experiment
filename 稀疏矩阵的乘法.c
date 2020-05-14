#include <stdio.h>
#include <stdlib.h>

template<
typename T
>

int findX(T *a, int n, T b) {
    int l = 0, r = n;
    int mid;
    do {
        mid = (l + r) / 2;
        if (a[mid] < b || a[mid] == b) l = mid;
        else r = mid;
    } while (l + 1 < r);
    return a[l] == b ? l : -1;
}


typedef struct {
    int r;
    int c;
    int v;
} Triple;

bool operator<(const Triple

& a, const Triple& b){
return a.r<b.r || (a.r == b.r && a.c < b.c );}
bool operator
==(const Triple& a, const Triple& b){
return (a.r == b.r && a.c == b.c );}
typedef struct {
    Triple data[100];
    int rpos[100];//position
    int m;
    int n;
    int t;
} SMatrix, *Matrix;

#define DEBUG_ //testDebug

void testDebug(Matrix a) {
    fprintf(stderr, "d: ");
    int i;
    for (i = 0; i < a->m; ++i) fprintf(stderr, "%i ", a->rpos[i]);
    fprintf(stderr, "\nd: t: %d\n", a->t);
    for (i = 0; i < (a->t); ++i)
        fprintf(stderr, "\td: (%i, %i) -> %i\n", a->data[i].r, a->data[i].c, a->data[i].v);
}

void Create(Matrix M) {
    int i;
    scanf("%d%d", &M->m, &M->n);
    for (i = 0;; i++) {
        scanf("%d%d%d", &M->data[i].r, &M->data[i].c, &M->data[i].v);
        M->rpos[i] = 0;
        if (M->data[i].r == 0)
            break;
    }
    M->t = i;
}

#define DEPR(arr, n) do{ fprintf(stderr, "darr: "); \
int i; for(i=0; i<n; ++i) fprintf(stderr, "%g ", arr[i]); \
fprintf(stderr, "\n");}while(0)

int seek(Matrix A, int r, int c) {
    int id = findX(A->data, A->t, (Triple) {r, c, 0});
    return id < 0 ? 0 : A->data[id].v;

//	int i;
//	for(i=0; i<A->t; ++i) if(A->data[i].r == r && A->data[i].c == c) return A->data[i].v;
//	return 0;
}

int Multiply(Matrix A, Matrix B, Matrix Q) {
    int arow, brow, ccol, p, q;
    int i, j, k;
    if (A->n != B->m) {
        return 0;
    }
    Q->m = A->m;
    Q->n = B->n;
    Q->t = 0;
    for (i = 1; i <= Q->m; i++) {
        for (j = 1; j <= Q->n; j++) {
            int v = 0;
            for (k = 1; k <= A->n; ++k) {
                v += seek(A, i, k) * seek(B, k, j);
            }
            if (v != 0) {
                Q->data[Q->t].r = i;
                Q->data[Q->t].c = j;
                Q->data[Q->t].v = v;
                Q->t++;
            }
        }
    }

    DEBUG_(Q);
    return 1;
}

void Print(Matrix M) {
    int i;
    for (i = 0; i < M->t; i++) {
        printf("%d %d %d\n", M->data[i].r, M->data[i].c, M->data[i].v);
    }
}

int main() {
    SMatrix A, B, C;
    Create(&A);
    DEBUG_(&A);
    Create(&B);
    DEBUG_(&B);
    Multiply(&A, &B, &C);
    Print(&C);
    return 0;
}//
// Created by sqx08 on 2020/5/14.
//

