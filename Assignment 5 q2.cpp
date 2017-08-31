#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
    int data;
    struct node* left =NULL;
    struct node* right =NULL;
}node;

void preOrder(node* root) {
    cout<<root->data<<" ";      //first node
    if(root->left)
        preOrder(root->left);       //then left
    if(root->right)
    preOrder(root->right);          //then right
}


void postOrder(node *root) {
    if(root->left)                  //First left
        postOrder(root->left);
    if(root->right)
        postOrder(root->right);     //then right
    cout<<root->data<<" ";          //then node
}

void inOrder(node *root) {      // Recursion
    if(root->left)
        inOrder(root->left);        //First left
    cout<<root->data<<" ";          //Then root
    if(root->right)                 //them=n right
        inOrder(root->right);
}

void levelOrder(node * root) {
  node* temp;
  if(root==NULL)
      return;
  queue <node*> q;   // Maintaining queue
  q.push(root);
  while(!q.empty())
  {
      temp=q.front();   //Taking value from front
      q.pop();
      cout<<temp->data<<" ";
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
  }
}

node* MakeBinary(node* G,int n)
{
    node* temp;
    if(G==NULL)
    {
        G=new(node);
        G->data=n;
    }
    else
    {
        temp=G;
        while(1)
        {
            if(temp->data<n){                   //Checking value is less than data or not
                if(temp->right==NULL){
                        temp->right=new(node);
                        temp=temp->right;
                        temp->data=n;
                    break;
                }
                temp=temp->right;
            }
            else{
                if(temp->left==NULL){
                        temp->left=new(node);
                        temp=temp->left;
                        temp->data=n;
                    break;
                }
                temp=temp->left;
            }
        }
    }
    return G;
}


int main()
{
    cout<<"Enter the number of data"<<endl;
    int n,x;
    cin>>n;
    node * G= NULL;    //Head of tree
    cout<<"Enter data"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        G=MakeBinary(G,x);   //making binary tree
    }
    cout<<"In order"<<endl;
    inOrder(G);
    cout<<endl<<"Pre order"<<endl;
    preOrder(G);
    cout<<endl<<"Post order"<<endl;
    postOrder(G);
    cout<<endl<<"Level order"<<endl;
    levelOrder(G);
    return 0;
}
