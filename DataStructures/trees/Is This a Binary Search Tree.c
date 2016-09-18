/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
int check(Node *root,int max, int min){
	int l,r;
	if(root==NULL)
	return 1;
	
	
	l=check(root->left,root->data,min);
	r=check(root->right,max,root->data);
	if(l!=1||r!=1)
		return 0;
	if(root->left==NULL&&root->right==NULL)
		return 1;
	if(root->left&&root->right)
		if(root->data>root->left->data && root->left->data> min && root->data< root->right->data && root->right->data<max)
			return 1;
		else 
			return 0;
	if(root->left!=NULL&&root->data>root->left->data || root->right!=NULL&&root->data< root->right->data)
		return 1;
	
	return 0;
}
	bool checkBST(Node* root) {
        return check(root,10000000,-1)?true:false;
    }
