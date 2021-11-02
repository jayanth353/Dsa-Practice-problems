// Algo: while queue is not empty
//           1 pop an element
//           2 push left child first and then right childs to queue
//           3 print the poped value (or push to vector)
           
vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      queue<Node*> l;
      l.push(node);
      while(!l.empty())
      {
          Node*temp=l.front();
          l.pop();
          if(temp->left) l.push(temp->left);
          if(temp->right) l.push(temp->right);
          ans.push_back(temp->data);
      }
      return ans;
    }

/*Reveresed level order*/
//1. while queue is not empty
//           1.1 pop an element
//        !!!1.2 push right child first and then left childs to queue
//           1.3 push the poped value into the stack
//2.print the values in the stack

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        if(q.front()->right) q.push(q.front()->right); 
        if(q.front()->left) q.push(q.front()->left);
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans;
    
}
