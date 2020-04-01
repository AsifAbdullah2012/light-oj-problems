#include<bits/stdc++.h>
#define inf -100000000
using namespace std;

int arr[102];
int n;
int dp[102][202];


int call(int i,int j)
{
   if(i>j) return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int sum=0,diff=inf;

    for(int k=i;k<=j;k++)
    {
        sum+=arr[k];
        diff=max(diff,sum-call(k+1,j));
    }

    sum=0;

    for(int k=j;k>=i;k--)
    {
        sum+=arr[k];
        diff=max(diff,sum-call(i,k-1));
    }
    return dp[i][j]=diff;

}







int main()
{
    int i,j,k,t;
    scanf("%d",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
       printf("Case %d: ",kk1);
       printf("%d\n",call(0,n-1));
    }


}
