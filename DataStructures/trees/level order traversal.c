
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/
int a[10000000];int i=0,last;
void calc(node *root){
     
    if(root==NULL)return;
     a[i]=root->data;
     if(root->left)
     { a[i*2+1]=root->left->data;last=i*2+1;}
     if(root->right)
     { a[i*2+2]=root->right->data;last=i*2+2;}
    i=i*2+1;
    calc(root->left);
    i=i/2;
    i=i*2+2;
    calc(root->right);
    i=(i-1)/2;
     
}
void LevelOrder(node * root)
{
     if(root==NULL)return;
    for(int i=0;i<10000000;i++)
        a[i]=-999999;
    calc(root);
    int j;
    for(j=0;j<=last;j++){
        if(a[j]!=-999999)
        cout<<a[j]<<" ";
    }
  
}


