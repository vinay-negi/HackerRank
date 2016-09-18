#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int data;
    int max;
    node *next;
};
void push(node **top,int n){
    node  *p=NULL;
    p=(node*)malloc(sizeof(node));
    p->data=p->max=n;
    p->next=NULL;
    if(*top==NULL){
        *top=p;
        return;
    }
    if((*top)->max>n)
    p->max=(*top)->max;
    p->next=*top;
    *top=p;       
}
void pop(node **top){
	if(*top==NULL)return;
	node *t=*top;
	*top=t->next;
	free(t);
}
 
int _max(node *top){
	if(top==NULL)return -1;
	return top->max;
}
int main() {
    node *top=NULL;
    int ch,n;
    cin>>n;
    while(n){
        cin>>ch;
        if(ch==1){
            cin>>ch;
            push(&top,ch);
        }
        else if(ch==2){
            pop(&top);
        }
        else {
            cout<<_max(top)<<"\n";
        }
        n--;
    }
     
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

