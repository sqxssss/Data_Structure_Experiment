/*#include<stdio.h>
#include<stdlib.h>
int k;
typedef struct node {
	int data;
	struct node*next;
	struct node*pre;
}node,*list;
void init(list l)
{
    list tail = l, p;
	p=(list)malloc(sizeof(node));
	tail->next = p;
	p->pre = tail;
	tail = p;
	p->data = 2;
	tail->next = NULL;
}
void destorylist(list l)
{
	list p=l->next;
	list q;
	while (p->next)
	{
		q = p->next;
		free(p);
		p = q;
	}           //将头结点后逐项释放
	free(l);   //最后释放头结点
	l = NULL;
}
void insert(list l, int data)
{
	list p = l;
	if(p == NULL)
	{
		return;
	}
	else
	{
		while (p->next)
			p = p->next;
		list temp = (list)malloc(sizeof(node));
		p->next = temp;
		temp->data = data;
		temp->pre = p;
		temp->next = NULL;
	}
}
void traverse(list l)
{
	printf("%d.",l->next->data);
	l=l->next;
	list p;
	p=l->next;
	while(p!=NULL&&k)
	{
		printf("%d",p->data);
		p=p->next;
		k--;
	}
	printf("\n");
}
void SumAll(list p,list suml)
{
    list q,sum;
	int ret,tmp,cnt=3,num=1;
	int sign=1;
	while(sign)
	{
		q=p->next;
		sum=suml->next;
		ret=0;
		while(q->next)
		{
			q=q->next; //q指向p的最后一位
		}
		while (q)
		{
			tmp=q->data*num+ret;
			q->data=tmp%10;
			ret=tmp/10; //这个是进位
			if(q->pre==NULL)break;
			else
			{
				q=q->pre;
			}
		}   //乘法运算
		ret=0;
		q=p->next;
		while (q)
		{
			tmp=q->data+ret*10;
			q->data=tmp/cnt;
			ret=tmp%cnt;
			if(q->next==NULL)break;
			else
			{
				q=q->next;
			}
		}  // 除法运算
		q=p->next;
		sum=sum1->next;
		while(q->next&&sum->next)
		{
			q=q->next;
			sum=sum->next;
		}
		sign=0;
		while (q&&sum)
		{
            tmp=sum->data+q->data ;
			sum->data=tmp%10;
			if(sum->pre==NULL||q->pre==NULL)
			{
				break;
			}
			else
			{
				sum->pre->data+=tmp/10;
				sign |= q->data;
				sum=sum->pre;
				q=q->pre;
			}
		}
		num++;
		cnt+=2;
	}
}
int main()
{
	list p;
	list sum1;
	int i;
	scanf("%d",&k);
	p=(list)malloc(sizeof(node));
	sum1=(list)malloc(sizeof(node));
	p->next = NULL;
	sum1->next=NULL;
	p->pre = NULL;
	sum1->pre=NULL;
	init(p);
	init(sum1);
    for(i=1;i<=500;i++)
	{
		insert(p,0);
		insert(sum1,0);
	}
	SumAll(p,suml);
	traverse(sum1);
	destorylist(p);
	destorylist(sum1);
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>

int k;

typedef struct node {
    int data;
    struct node *next;
    struct node *pre;
} node, *list;

void init(list l) {
    list p = l, q;
    int i;
    p->next = p->pre = l;
    for (i = 0; i < 1000; i++) {
        q = (list) malloc(sizeof(node));
        q->data = 0;
        p->next = q;
        q->pre = p;
        q->next = l;
        l->pre = q;
        p = q;
    }
}

void destorylist(list l) {
    list p = l->next;
    list q;
    while (p != l) {
        q = p->next;
        free(p);
        p = q;
    }           //将头结点后逐项释放
    free(l);   //最后释放头结点
    l = NULL;
}


void traverse(list sum) {
    int i;
    if (k == 0)
        printf("3\n");
    else {
        sum = sum->next;
        printf("%d.", sum->data);
        for (i = 0; i < k; i++) {
            printf("%d", sum->next->data);
            sum = sum->next;
        }
    }
}

void Sum(list q, list sum) {
    list a = q->pre, b = sum->pre;
    int tmp;
    while (b != sum) {
        tmp = a->data + b->data;
        b->data = tmp % 10;
        b->pre->data += tmp / 10;
        a = a->pre;
        b = b->pre;
    }
}

void Multiply(list q, int n) {
    list a = q->pre;
    int ret = 0, tmp = 0;
    for (; a != q; a = a->pre) {
        tmp = (a->data) * n + ret;
        ret = tmp / 10;
        a->data = tmp % 10;
    }
    tmp = (a->data) * n + ret;
    ret = tmp / 10;
    a->data = tmp % 10;
}

void Divide(list q, int n) {
    list a = q->next;
    int tmp = 0, ret = 0;
    for (; a != q; a = a->next) {
        tmp = a->data + 10 * ret;
        a->data = tmp / n;
        ret = tmp % n;
    }
}

int main() {
    list p, sum;
    int mother, son, s = 1;
    scanf("%d", &k);
    p = (list) malloc(sizeof(node));
    sum = (list) malloc(sizeof(node));
    init(p);
    init(sum);
    p->next->data = 3;
    sum->next->data = 3;
    while (s < 1000) {
        son = (2 * s - 1) * (2 * s - 1);
        mother = 8 * s * (2 * s + 1);
        Multiply(p, son);
        Divide(p, mother);
        Sum(p, sum);
        s++;
    }
    traverse(sum);
    destorylist(p);
    destorylist(sum);
    return 0;
}
//
// Created by sqx08 on 2020/4/24.
//

