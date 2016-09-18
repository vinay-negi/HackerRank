#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
	int index;
	struct node *left,*right;
}node;
typedef struct queue{
	node *data;
	struct queue *next;
}queue;
void print(node* root){
	if(root==NULL)return;
	print(root->left);
	printf("%d ",root->index);
	print(root->right);
}
void inque(queue **head,queue**tail,node *data){
	queue *t=(queue*)malloc(sizeof(queue));
	t->next=NULL;
	t->data=data;
	
	if(*tail){
		(*tail)->next=t;
		*tail=t;
	}
	else
		*head=*tail=t;
	//print(data);
}
node* deque(queue **head,queue **tail){
	if(*head==NULL)return NULL;
	queue *t=(*head)->next;
	node *x=(*head)->data;
	 
	if(t==NULL)
		*tail=NULL;
	free(*head);
	*head=t;
	return x;
}
node *ins(int data){
	if(data==-1)
		return NULL;
	node *t=(node*)malloc(sizeof(node));
	t->left=t->right=NULL;
	t->index=data;
	return t;
}
 
node* insert(node* root,int *a,int n){
	queue *head=NULL,*tail=NULL;node *t=NULL;
	inque(&head,&tail,root);
	int i=0;
	t=root;
	while(head){
		t=deque(&head,&tail);
		if(t){
			t->left=ins(a[i]);
			if(a[i]!=-1)
			inque(&head,&tail,t->left);
			i++;
		
			t->right=ins(a[i]);
			if(a[i]!=-1) 
			inque(&head,&tail,t->right);
			i++;  
		
		}
	}
	return root;
}
void swap(node** l,node **r){
	node *t=*l;
	*l=*r;
	*r=t;
}
void swapnode(node *root,int k){
	if(root==NULL)return;
	if(k==1){
		swap(&(root->left),&(root->right));
		return;
	}
	swapnode(root->left,k-1);
	swapnode(root->right,k-1);
	
}
 void _free(node **root){
	if(*root==NULL)
		return;
	_free(&(*root)->left);
	_free(&(*root)->right);

	free((*root)->left);
	free((*root)->right);
	(*root)->left=(*root)->right=NULL;
	free(* root);
	*root=NULL;
	
}
int calcdepth(node* root){
	if(root==NULL)return 0;
	if(root->left==NULL&&root->right==NULL)
	return 1;
	int l=calcdepth(root->left)+1;
	int r=calcdepth(root->right)+1;
	return l>r?l:r;
}
int main() {
	node *root=NULL;
	int n,i,j,a[2048],k;
	scanf("%d",&n);
	root=(node*)malloc(sizeof(node));
	root->index=1;
	root->left=root->right=NULL;
	for(i=0;i<n*2;i++)
		scanf("%d",&a[i]);
 	root=insert(root,a,2*n);
 	scanf("%d",&n);
 	i=0;
 	int depth=calcdepth(root);
 	while(i<n){
 		i++;
 		scanf("%d",&k);
 		j=k;
 		while(k<=depth){
 			swapnode(root,k);
	 		k+=j;
		}
	 	print(root);printf("\n");
	}
  
 	_free(&root);
	root=NULL;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

