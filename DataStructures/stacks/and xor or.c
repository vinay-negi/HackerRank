#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
Node* push(Node *top,int data){
	Node *t=(Node*)malloc(sizeof(Node));
	t->data=data;
	t->next=top;
	return t;
}
//void print(Node* top){
//	while(top){
//		printf("%d ",top->data);
//		top=top->next;
//	}
//}
void pop(Node** top){
	if(top==NULL||*top==NULL)
	return;
	Node *t=*top;
	t=t->next;
	free(*top);
	*top=t;
}
int main() {

	Node *top=NULL;
	int n;
	long long int data,max=0;
	scanf("%d",&n);
	while(n--){
		scanf("%lld",&data);
		if(top==NULL)
			top=push(top,data);
		else{
			while(top&&data<top->data){
				if(max<((data^top->data)))
				max=data^(top->data);
				pop(&top);
			//	printf("%d\n",max);
			}
			if(top && ((top->data)^data)>max) 
				max=(top->data)^data;
			top=push(top,data);
		}
	}
	while(top){
		if(top->next && ((top->data)^(top->next->data))>max)
			max=(top->data)^(top->next->data);
		top=top->next;
	}
	printf("%lld\n",max);
	//print(top);
    return 0;
}
