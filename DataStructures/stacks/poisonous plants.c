#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct stack{
	long long int data;
	int day;
	struct stack *next;
}stack;
 int max=0;
void push(stack** top,long long int data){
	stack *p=(stack*)malloc(sizeof(stack));
	p->data=data;
	p->next=*top;
	*top=p;
}
 
void pop(stack** top){
	int val;
	stack* t=*top;
	val=t->day;
	*top=t->next;
	free(t);
 
}
void calc(stack** top,int data){
	int val=0;
	if(*top==NULL)
	{
		push(top,data);
		(*top)->day=0;
		return;
	}
	if(data<=(*top)->data){
		val=(*top)->day;
		while(*top && data<=(*top)->data)
		{
			if(val<(*top)->day)
			val=(*top)->day;
			pop(top);
		}
		if(*top==NULL){
			push(top,data);
			(*top)->day=0;
		}
		else
		{
			 
			push(top,data);
			(*top)->day=1+val;
			if(max<(*top)->day)
			max=(*top)->day;
		}
	}
	else{
		push(top,data);
		(*top)->day=1;
		if(max<(*top)->day)
			max=(*top)->day;
	} 
	
}

 int main() {
	stack *top=NULL,*top2=NULL;
	 int n;long long int i;
	scanf("%d",&n);
	while(n){
		n--;
		scanf("%lld",&i);
		calc(&top,i);
	}
	printf("%d",max);
	 
	
 
	return 0;
}

