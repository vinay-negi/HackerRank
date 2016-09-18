#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
void push(Node** top,int val){
	Node *t=(Node*)malloc(sizeof(Node));
	t->data=val;
	t->next=*top;
	*top=t;
}
int main() {
	int n,q,i;
	Node* top=NULL;
	Node* top2=NULL;
	int prime[1200];
	scanf("%d%d",&n,&q);
	while(n--){
		int val;
		scanf("%d",&val);
		if(val%2)
		push(&top,val);
		else
		printf("%d\n",val);
	}
	prime[0]=2;
	int flag=1,lim=1;
	i=0;n=3;
	while(lim<q){
		flag=1;
		for(i=0;i<lim;i++){
			if(n%prime[i]==0){
				n++;
				flag=0;break;
			}			
		}
		if(flag)
		prime[lim++]=n++;
	} 
	i=1;
	while(i<lim){
		while(top){
			Node *t=top;
			if(top->data%prime[i]==0)
				printf("%d\n",top->data);
			else
				push(&top2,top->data);
			top=top->next;
			free(t);
		}
		i++;
		top=top2;
		top2=NULL;
	}
	while(top){
		push(&top2,top->data);
		top=top->next;
	}
	while(top2){
		printf("%d\n",top2->data);
		top2=top2->next;
	}
	
    return 0;
}

