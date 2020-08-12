// 1406번 : 에디터
#include <stdio.h>
#include <malloc.h>
#define DEBUG 0
typedef struct _que
{
	char c;
	struct _que * prev;
	struct _que * next;
} Que;

Que Head = { 0 };
Que * Wr = &Head;
Que * Rd = &Head;

void In_Q(Que * d);
#if DEBUG
void Print_Queue(void);
#endif

int main(void)
{
	Que tmp = { 1, 0, 0 };
	int n;
	int i;
	char t;
	char str[100010] = { 0 };
	int len;

	scanf("%s", str);
	for (len = 0; str[len]; len++)
	{
		tmp.c = str[len];
		In_Q(&tmp);
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
	
		scanf(" %c", &t);
		if (t == 'P')
		{
			scanf(" %c", &t);
			tmp.c = t;
			In_Q(&tmp);
		}
		else if (t == 'L' && Wr->prev != (Que *)0x0)
		{
			Wr = Wr->prev;
		}
		else if (t == 'D' && Wr->next != (Que *)0x0)
		{
			Wr = Wr->next;
		}
		else if (t == 'B' && Wr->prev != (Que *)0x0)
		{
			Wr->prev->next = Wr->next;
			if (Wr->next != (Que *)0x0) Wr->next->prev = Wr->prev;
			Wr = Wr->prev;
			Rd = Head.next;
		}
#if DEBUG
		printf("[%c]", t);
		Print_Queue();
		printf("\n");
#endif
	}

	while (Rd)
	{
		printf("%c", Rd->c);
		Rd = Rd->next;
	}
	printf("\n");

	return 0;
}

void In_Q(Que * d)
{
	Que * p = (Que *)calloc(1, sizeof(Que));
	if (p == (Que *)0x0) return;

	*p = *d;
	if (Wr == &Head)
	{
		Rd = Wr = p;
		if (Head.next)
		{
			Head.next->prev = p;
			p->next = Head.next;
		}
		Head.next = p;
		p->prev = &Head;
	}
	else 
	{
		p->next = Wr->next;
		p->prev = Wr;
		if (Wr->next != (Que *)0x0) Wr->next->prev = p;
		Wr->next = p;

		Wr = p;
	}
}
#if DEBUG
void Print_Queue(void)
{
	Que * t = Rd;

	printf("Head = 0x%.8x, prev = 0x%.8x, next = 0x%.8x\n", &Head, Head.prev, Head.next);
	printf("Rdptr = 0x%.8x\n", Rd);
	while (t)
	{
		printf("addr = 0x%.8x, c = %c, prev = 0x%.8x, next = 0x%.8x\n", t, t->c, t->prev, t->next);
		t = t->next;
	}
	printf("Wrptr = 0x%.8x\n", Wr);

}
#endif