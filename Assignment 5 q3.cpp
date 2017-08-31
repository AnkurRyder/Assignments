#include <iostream>
#include <queue>

using namespace std;

typedef struct node  //Information and address of next node
{
  int data;
  struct node* leftad=NULL;
  struct node* rightad=NULL;
}node;
node* MakeBinary(node* G,int n);
void AllPath(node *G,queue<int> A)
{
    queue<int> Q=A;
    if(G->leftad!=NULL||G->rightad!=NULL){      //If at least one node is connected
        Q.push(G->data);
        if(G->leftad!=NULL)
            AllPath(G->leftad,Q);
        if(G->rightad!=NULL)
            AllPath(G->rightad,Q);
    }
    else
    {
        while(!Q.empty())
        {
            cout<<Q.front()<<" ";
            Q.pop();
        }
        cout<<G->data;          //Last node value
        cout<<endl;
    }
}
int main()
{
    int n,x;
    cin>>n;
    node* G= NULL;    //Head of tree
    for(int i=0;i<n;i++)
    {
        cin>>x;
        G=MakeBinary(G,x);   //making binary tree
    }
    queue<int> Q;
    AllPath(G,Q);
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
    return(G);
}
