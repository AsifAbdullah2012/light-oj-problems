#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>

using namespace std;
string ss;
long long dp[65][65];

long long solve(long long a,long long b)
{
    if(b<a)
    return 0;

    if(a==b)
        return 1;

    if(dp[a][b]!=-1)
        return dp[a][b];

    long long int ret=0;

    if(ss[a]==ss[b])
    {
        ret=1+solve(a+1,b)+solve(a,b-1);
    }
    else
    {
        ret=solve(a+1,b)+solve(a,b-1)-solve(a+1,b-1);
    }

    return dp[a][b]=ret;

}



int main()
{
    int i,j,k,t;
    long long ans;
    scanf("%d",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {
        cin>>ss;
        memset(dp,-1,sizeof(dp));
        ans=solve(0,ss.size()-1);
        printf("Case %d: ",kk1);
        printf("%lld\n",ans);

    }





}
