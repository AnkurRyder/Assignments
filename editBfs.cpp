#include<bits/stdc++.h>

using namespace std;
#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<int > vi;
typedef pair<int ,int> pi;
typedef vector<pi> vpi;
typedef vector<vi > vvi;



void bfs(string s1,string s2)
{
    queue<pair<string,pair<int,int> > > q;  // string , pointer , height
    q.push({s1,{0,0}});
    int l2=s2.length();
    while(!q.empty())
    {
        string s3=q.front().first;
        int l3=s3.length();
        int p=q.front().second.first; // pointer
        int h=q.front().second.second; // height
         cout<<s3<<" "<<h<<endl;
        q.pop();
        if(s3==s2)
        {
            cout<<s3<<" "<<s2<<" "<<h<<endl;
            cout<<"success";
            return ;
        }
        if(s3!="")
        	q.push({s3 , {(p+1)%l3 , h+1}});
        rep(i , 0, l2-1)
        {
            string s=s3;
            s.insert(s.begin()+p,s2[i]);
            q.push({s,{p+1,h+1}});
        }
        if(p!=-1)
        {
            if(l3-1==p)
            {
                s3.erase(s3.begin()+p);
                q.push({s3,{-1,h+1}});
            }
            else
            {
                s3.erase(s3.begin()+p);                  
                q.push({s3,{p,h+1}});
            }

        }
             
   }
}


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int h=0;
    bfs(s1,s2);
}