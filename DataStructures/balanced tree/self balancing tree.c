/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node * getNode(int val){
    node* t=(node*)malloc(sizeof(node));
    t->val=val;
    t->left=t->right=NULL;
    t->ht=0;
    return t;
}
int max(node* l,node*r){
    int x=-1;
    if(l)
        x=l->ht;
    if(r&&r->ht>x)
        x=r->ht;
    return x;
}
int height(node* t){
    if(t)
        return t->ht;
    return -1;
}
node* rtt(node* y){
    node*x=y->left;
    node*t=x->right;
    x->right=y;
    y->left=t;
    y->ht=max(y->left,y->right)+1;
    x->ht=max(x->left,x->right)+1;
    return x;
}
node *ltt(node* x){
    node *y=x->right;
    node *t=y->left;
    y->left=x;
    x->right=t;
    x->ht=max(x->left,x->right)+1;
    y->ht=max(y->left,y->right)+1;
    return y;
}
node * insert(node * root,int val)
{
    
    if(root==NULL)
       return getNode(val);
    if(root->val>val)
       root->left=insert(root->left,val);
    else
       root->right=insert(root->right,val);
       
    root->ht=max(root->left,root->right)+1;
    //cout<<root->ht<<endl;
    int bal=height(root->left)-height(root->right);
    
    if(bal>1&&val<(root->left->val))
        return rtt(root);
    if(bal>1&&val>(root->left->val)){
        root->left=ltt(root->left);
        return rtt(root);
    }
    if(bal<-1&&val>(root->right->val))
        return ltt(root);
    if(bal<-1&&val<(root->right->val)){
        root->right=rtt(root->right);
        return ltt(root);
    }
    return root;
    
  
}

