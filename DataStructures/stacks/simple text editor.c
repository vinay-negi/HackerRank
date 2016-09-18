#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct stack{
	char c;
	int i;
	struct stack* next;
}stack;
typedef struct flag{
	int i;
	struct flag *next;
}flag;
typedef struct ins{
	int i;	
	struct ins* next;
}ins;
typedef struct del{
	char c;
	int i;
	struct del* next;
}del;
void push(stack **top,char c){
	stack *p=(stack*)malloc(sizeof(stack));
	p->next=*top;
	p->c=c;
	if(*top==NULL)
		p->i=1;
	else
		p->i=(*top)->i+1;
	*top=p;
}
char pop(stack** top){
	stack *t=*top;
	char c=t->c;
	*top=t->next;
	free(t);
	return c;
}
void print(stack *top,int i){
	if(i>top->i)return;
	while(top->i!=i)
	top=top->next;
	printf("%c\n",top->c);
}
void pushflag(flag** flg,int i){
	flag *p=(flag*)malloc(sizeof(flag));
	p->i=i;
	p->next=*flg;
	*flg=p;
}
void insert(ins** in,int i){
	ins *p=(ins*)malloc(sizeof(ins));
	p->i=i;
	p->next=*in;
	*in =p;
}
void _delete(del** de,char c,int i){
	del *p=(del*)malloc(sizeof(del));
	p->c=c;
	p->i=i;
	p->next=*de;
	*de=p; 
}
void undo(stack **top,flag** flg,ins** in,del** de){
	flag *t=*flg;
	del* d=NULL;
	ins *ii=*in;
	int tmp;
	if( t->i==0){
		tmp=ii->i;
		while(tmp){
			tmp--;
			pop(top);
		}
		*in=ii->next;
		free(ii);
	}
	else
	{
		
		d=*de;
		push(top,d->c);
		*de=d->next;
		free(d);
		d=*de;
		while(d&&d->i){
			push(top,d->c);
			*de=d->next;
			free(d);
			d=*de; 
		}
	}
	
	*flg=t->next;
	free(t);
}
int main() {
	stack *top=NULL;
	flag *flg=NULL;
	ins* in=NULL;
	del* de=NULL;
	char s[1000000];
	int i,q,t;
	scanf("%d",&q);
	while(q){
		q--;
		scanf("%d",&t);
		switch(t){
			case 1:
				pushflag(&flg,0);
				scanf("%s",s);
				i=0;
				while(s[i]){
					push(&top,s[i++]);
				}
				insert(&in,i);
				break;
			case 2:
				pushflag(&flg,1);
				scanf("%d",&i);
				while(i){i--;
					_delete(&de,pop(&top),i);
				}
				
				break;
			case 3:
				scanf("%d",&i);
				print(top,i);
				break;
			case 4:
				undo(&top,&flg,&in,&de);
				break;
				
		}
	}
    return 0;
}

