/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
void _left(node *root){
    if(root==NULL)return;
    _left(root->left);
    cout<<root->data<<" ";
}
void _right(node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    _right(root->right);
}
void top_view(node * root)
{
    
    if(root==NULL)return;
    if(root->left)
    _left(root->left);
    cout<<root->data<<" ";
    if(root->right)
    _right(root->right);
     
  
}

