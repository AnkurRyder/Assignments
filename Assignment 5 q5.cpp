#include <iostream>

using namespace std;
int key=0,ok=0;

typedef struct node  //Information and address of next node
{
  int data;
  struct node* leftad=NULL;
  struct node* rightad=NULL;
}node;

node* MakeBinary(node* G,int n);

void inOrder(node *root,int value){      // Recursion
    if(root->leftad)
        inOrder(root->leftad,value);
    if(root->data==value||key==1){
            if(key==1){
                cout<<root->data<<endl;
                ok=1;
                key=0;
                return;
            }
            else
                key=1;
    }
    if(root->rightad)                 //then right
        inOrder(root->rightad,value);
}

int main()
{
    int n,x,value;
    cin>>n;
    node * G= NULL;    //Head of tree
    for(int i=0;i<n;i++)
    {
        cin>>x;
        G=MakeBinary(G,x);   //making binary tree
    }
    cin>>value;
    inOrder(G,value);
    if(ok==0)
        cout<<"No Successor"<<endl;
    return 0;
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
                if(temp->rightad==NULL){
                        temp->rightad=new(node);
                        temp=temp->rightad;
                        temp->data=n;
                    break;
                }
                temp=temp->rightad;
            }
            else{
                if(temp->leftad==NULL){
                        temp->leftad=new(node);
                        temp=temp->leftad;
                        temp->data=n;
                    break;
                }
                temp=temp->leftad;
            }
        }
    }
    return G;
}

