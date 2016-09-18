/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

int print(node *root,string s,int i){
    if(root==NULL)return i;
      if(root->left==NULL&&root->right==NULL)
       { cout<<root->data;return i;
       }
    if(root->left&&s[i]=='0')
     return   print(root->left,s,i+1);
    else
     return   print(root->right,s,i+1);
    
    
}
void decode_huff(node * root,string s)
{
    static int i=0;
    if(root==NULL)return;
     while(s[i]=='0'||s[i]=='1'){
      i=  print(root,s,i);
        
   }
     
}

