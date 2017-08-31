#include <iostream>
#include <vector>

int main()
{
    int n,x,k,temp;
    cout<<"Enter the length of the array"<<endl;
    cin>>n;
    cout<<"Enter the values"<<endl;
    vector <int> A(n,0);
    for(int i=0;i<n;i++){
        cin>>tem;
        A[temp]=1;
    }
    cout<<"X = "<<endl;
    cin>>x;
    cout<<"K = "<<endl;
    cin>>k;
    int i=x;
    while(k>0)
    {
        if(A[i]&&i<n)
        {
            cout<<i;
            k--;
        }
        else
        {
            if(A[n-i]&&i>0)
            {
                cout<<i;
                k--;
            }
            i++;
        }
    }
    return 0;
}
