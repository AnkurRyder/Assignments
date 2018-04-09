#include <bits/stdc++.h>

using namespace std;

int edit(string s1 , string s2 , int m , int n)
{
    int A[m+1][n+1];
    for (int i=0; i<=m ;i++)
    {
        for (int j=0;j <= n ;j++)
        {
            if (i == 0)
            {
                A[i][j] = j;
            }
            else if(j == 0)
            {
                A[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1])
            {
                A[i][j] = A[i-1][j-1];
            }
            else
            {
                A[i][j] = 1+ min(A[i-1][j-1],min(A[i-1][j], A[i][j-1]));
            }
        }
    }
    return A[m][n];
}
int main()
{
    string s1 , s2;
    cin >> s1 >> s2;
    cout <<edit(s1 , s2 , s1.length() , s2.length()) <<"\n";
    return 0;
}
