#include<bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<char > vc;
typedef vector<vc > vvi;

bool check(vc &m)
{
    if((m[0]+m[1]+m[2]==3*'x')||(m[0]+m[3]+m[6]==3*'x'))
        return true;
    if((m[2]+m[5]+m[8]==3*'x')||(m[6]+m[7]+m[8]==3*'x'))
        return true;
    if((m[1]+m[4]+m[7]==3*'x')||(m[3]+m[4]+m[5]==3*'x'))
        return true;
    if((m[0]+m[4]+m[8]==3*'x')||(m[2]+m[4]+m[6]==3*'x'))
        return true;
    return false;

}

bool check1(vc &m)
{
    if((m[0]+m[1]+m[2]==3*'o')||(m[0]+m[3]+m[6]==3*'o'))
        return true;
    if((m[2]+m[5]+m[8]==3*'o')||(m[6]+m[7]+m[8]==3*'o'))
        return true;
    if((m[1]+m[4]+m[7]==3*'o')||(m[3]+m[4]+m[5]==3*'o'))
        return true;
    if((m[0]+m[4]+m[8]==3*'o')||(m[2]+m[4]+m[6]==3*'o'))
        return true;
    return false;
}
int ll=0;

void bfs1( vc &m,int turn,char a)
{
    queue<pair<vc,pair<int,int>>>q; // string , no of turns , turn
    q.push({m,{0,turn}});
    while(!q.empty())
    {
        vc m=q.front().first;
        int  s=q.front().second.first;
        turn =q.front().second.second;

        q.pop();
        int c=0;

        cout<<ll++<<endl;
        rep(i,0,8)
        {
            cout<<m[i]<<"  ";
            if((i+1)%3 == 0)
                cout<<endl;
            if(m[i]!='_')
                c++;
        }
        cout<<endl;

        if(c==9)
        {
            continue;
        }
        if(a=='x'&&check(m)&&(!check1(m)))
        {

            cout<<"Player x win->"<<s << "\n";
            break;
        }else if(a=='o'&&check1(m)&&(!check(m)))
        {

            cout<<"Player o win->"<<s << "\n";
            break;
        }
        if(turn==1) // pushing if chance of X player
        {
            rep(i,0,8)
            {
                if(m[i]=='_') // player draw where place is empty
                {
                    vc mm(m.begin(),m.end());
                    mm[i]='x';
                    q.push({mm,{s+1,0}}); // push in q

                }
            }


        }
        else  //pushing if chance of O player
        {
            rep(i,0,8)
            {

                if(m[i]=='_')
                {
                    vc mm(m.begin(),m.end());
                    mm[i]='o';
                    q.push({mm,{s+1,1}});

                }
            }
        }

    }
    if(q.empty())
    {
        cout<<"PLayer "<<a<<" Impossible\n";
    }
}
int main()
{
    vc m(9);
    int hum=0,com=0;
    rep(i,0,8)
    {
       cin>>m[i];
       if(m[i]=='x')
       hum++;
       else if(m[i]=='o')
       com++;
    }
    int turn =0;
    if(com>hum)
        turn =1;
    bfs1(m,turn,'x');
    ll=0;
    bfs1(m,turn,'o');

}
