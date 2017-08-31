#include <iostream>

using namespace std;

typedef struct node  //Information and address of next node
{
  int data;
  struct node* leftad=NULL;
  struct node* rightad=NULL;
}node;
node* MakeBinary(node* G,int n);

void lca(node *root, int v1,int v2)
{
    node* temp=root;
    while(!((v1<=temp->data&&v2>=temp->data)||(v1>=temp->data&&v2<=temp->data)))    //while data is greater than both values
    {
        if(v1<temp->data&&v2<temp->data)
            temp=temp->leftad;
        else
            temp=temp->rightad;
    }
    cout<<temp->data<<endl;
}

int main()
{
    int n,x,v1,v2;
    cin>>n;
    node * G= NULL;    //Head of tree
    for(int i=0;i<n;i++)
    {
        cin>>x;
        G=MakeBinary(G,x);   //making binary tree
    }
    cin>>v1>>v2;
    lca(G,v1,v2);
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
