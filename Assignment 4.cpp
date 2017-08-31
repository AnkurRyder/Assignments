/* ********************************************
    ANKUR JAISWAL  16CS01024
    INDIAN INSTITUTE OF TECHNOLOGY BHUBANESWAR
    *******************************************
*/

#include <iostream>
#include <vector>

using namespace std;
typedef struct data
{
  int id;
  int likes;
}data;

void movedown(vector <data>& A,int n,int i);
void swap(vector <data>& A,int i,int j);
void buildBinaryHeap(vector <data>& a, int n);
void inser(vector <data>& A,data temp);
void uplike(vector <data>& A ,int id);
void downlike(vector <data>& A,int id);
void deleteId(vector <data>& A,int id);
void print(vector <data>& A);

int main()
{
    int n;
    cin>>n;
    vector <data> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i].id>>A[i].likes;
    buildBinaryHeap(A,n);
    print(A);
    int i=1,id;
    data temp;
    while(i)
    {
        cout<<"1 : Insert New Id"<<endl;
        cout<<"2 : Like Photo"<<endl;
        cout<<"3 : Dislike"<<endl;
        cout<<"4 : Delete Id"<<endl;
        cout<<"0 : Exit"<<endl<<endl;
        cout<<"Choose an option"<<endl;
        cin>>i;
        if(i==1)
        {
            cout<<"Enter unique Id and initial likes"<<endl;
            cin>>temp.id>>temp.likes;
            inser(A,temp);
        }
        else
        {
            if(i==2)
            {
                cout<<"Enter Id"<<endl;
                cin>>id;
                uplike(A,id);
            }
            else
            {
                if(i==3)
                {
                    cout<<"Enter Id"<<endl;
                    cin>>id;
                    downlike(A,id);
                }
                else
                {
                    if(i==4){
                        cout<<"Enter Id"<<endl;
                        cin>>id;
                        deleteId(A,id);
                    }
                }
            }
        }
        print(A);
    }
    return 0;
}

void print(vector <data>& A)
{
    int i=0,l,r;
    cout<<"("<<A[0].id<<" , "<<A[0].likes<<")"<<" ";
    while(i<=(A.size()-2)/2)
    {
        l=2*i+1;
        r=2*i+2;
        cout<<"("<<A[l].id<<" , "<<A[l].likes<<")"<<" ";
        if(r<A.size())
            cout<<"("<<A[r].id<<" , "<<A[r].likes<<")"<<" ";
        i++;
    }
    cout<<endl;
}
void buildBinaryHeap(vector <data>& A, int n)
{
    int i, start;
    start = (n-2)/2;
    for(i = start; i >= 0; i--)
    movedown(A, n, i);
}
void movedown(vector <data>& A,int n,int i)
{
    int max = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && A[l].likes > A[max].likes)
        max = l;
    if(r < n && A[r].likes > A[max].likes)
        max = r;
    if(max != i) {
        swap(A, i, max);
        movedown(A, n, max);
    }
}

void swap(vector <data>& A,int i,int j)
{
    data temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

void inser(vector <data>& A,data temp)
{
        A.push_back(temp);
        int i=A.size()-1;
        while(i>0)
        {
            if(A[(i-1)/2].likes<temp.likes)
                A[i]=A[(i-1)/2];
            else
                A[i]=temp;
            i=(i-1)/2;
        }
}

void uplike(vector <data>& A ,int id)
{
    int i=0;
    while(A[i].id!=id)
    {
        i++;
    }
    A[i].likes++;
    cout<<A.size()<<endl;
    buildBinaryHeap(A,A.size());
}

void downlike(vector <data>& A,int id)
{
     int i=0;
    while(A[i].id!=id)
    {
        i++;
    }
    A[i].likes--;
    buildBinaryHeap(A,A.size());
}

void deleteId(vector <data>& A,int id)
{
    int i=0;
    while(A[i].id!=id)
        i++;
    A[i].id=A[A.size()-1].id;
    A[i].likes=A[A.size()-1].likes;
    A.erase(A.end()-1);
    int l=2*i+1;
    int r=2*i+2;
    while((A[i].likes<A[l].likes||A[i].likes<A[r].likes)&&i<=(A.size()-2)/2)
    {
        if(A[l].likes<A[r].likes){
            swap(A,i,r);
            i=r;
        }
        else{
            swap(A,l,i);
            i=l;
        }
    }
}
