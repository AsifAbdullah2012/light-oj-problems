//dearrangement
 
#include<bits/stdc++.h>
#define ll long long
#define md 1000000007
 
using namespace std;
 
ll fact[1000+10];
ll ncr[1002][1002];
 
int main()
{
    ll i,j,n,m,k;
    fact[0]=1;
    for(i=1;i<=1001;i++)
    {
        fact[i]=(fact[i-1]*i)%md;
        ncr[i][i]=1;
        ncr[i][0]=1;
    }
    ncr[0][0]=1;
    for(i=1;i<=1000;i++)
    {
        for(j=1;j<=i;j++)
        {
           ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%md;
        }
    }
    int t;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
       scanf("%ld %ld %ld",&n,&m,&k);
       ll ans=fact[n-k];
       for(int ii=1;ii<=(m-k);ii++)
       {
           if(ii%2L==1L)
           {
               ans=(ans-ncr[m-k][ii]*fact[n-k-ii])%md;
           }
           else
           {
               ans=(ans+ncr[m-k][ii]*fact[n-k-ii])%md;
           }
       }
 
       ans = (ans*ncr[m][k])%md;
       if(ans < 0) ans += md;
       printf("Case %d: ",kk1);
       printf("%ld\n",ans);
 
    }
 
 
}
