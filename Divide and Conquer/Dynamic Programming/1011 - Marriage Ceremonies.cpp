#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define infi -10009

using namespace std;

int val[17][17];
int dp[17][2<<16];
int n;

int call(int i,int mask)
{
    if(i>=n)
        return 0;
    if(dp[i][mask]!=-1)
        return dp[i][mask];

     int ret,ans;

     ret=infi;

    for(int k=0;k<n;k++)
    {
        if((mask&(1<<k)))
            continue;
        else
            ret=max(ret,val[i][k]+call(i+1,(mask|(1<<k))));

    }

    return dp[i][mask]=ret;


}


int main()
{
    int i,j,k,t;
    scanf("%d",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&val[i][j]);
            }
        }

        memset(dp,-1,sizeof(dp));

        printf("Case %d: ",kk1);
        printf("%d\n",call(0,0));


    }


}
