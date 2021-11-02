node* min(node*root)
{
	node*curr = root;
	while (curr->left != NULL && curr) curr = curr->left;
	return curr;
}



node* delnode(node*root, int key)
{
	//1. Base case:If key is not found then we simply return root Null to calling function

	if (root == NULL) return NULL;


	//2.If key lies is in left subtree then me make recur call  by
	//passing root->left and key which returns updated  link to root->left

	if (key < root->val) root->left = delnode(root->left, key);



	//3.Similarly if key is in  right subtree

	if (key > root->val) root->right = delnode(root->right, key);

	//4.If key is equal to root->key then we will delete node and return updated link to calling function(i.e for step 1 or 2)

	else {

		//4.1.If node has one child

		//4.1.1, node with only right child

		if (root->left == NULL)
		{
			node*temp = root->right;
			delete root;
			return temp; //return to 2 or 3
		}

		//4.1.2. Node with only left child

		else if (root->right == NULL)
		{
			node*temp = root->left;
			delete root;
			return temp;//returns to 2 or 3
		}
		//4.1.3. NOTE:There is no need to consider a node with no childs as it is covered in 5.1

		//4.2 .Node with two childs

		else {
			node*temp = min(root->right);//searches for min key in a right subtree

			root->val = temp->val;//now the node to be deleted is replaced with min key(i.e the value is updated)

			root->right = delnode(root->right, temp->val);//After updation the min key node is deleted
		}

		//5.Returns to calling function (i.e mainly to main function call in each recur call)
		return root;
	}


}
