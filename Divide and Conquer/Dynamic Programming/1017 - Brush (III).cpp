#include<bits/stdc++.h>

using namespace std;

int profit[202],nxt[202];
int dp[202][202];///from 0 to i item using k th sweep
int k,n;


///knapsack dp

int fun(int i,int mov)
{
    if(i==n)
        return 0;
    if(mov>=k)
        return 0;
    if(dp[i][mov]!=-1)
        return dp[i][mov];

 //   cout<<i<<"---->"<<mov<<endl;

    int ret,pro1=0,pro2=0;
    pro1 = fun(i+1,mov);
    pro2 = profit[i]+fun(nxt[i]+1,mov+1);
    ret = max(pro1,pro2);

    return dp[i][mov] = ret;






}

int main()
{
    ///input

    int i,j,t,w,x;
    int arr[202];

    scanf("%d",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d %d",&n,&w,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&arr[i]);
        }

        sort(arr,arr+n);

        ///process


        for(i=0;i<n;i++)
        {
            profit[i]=1;
            nxt[i]=i;

            x = arr[i]+w;

            ///loop over

            for(j=i+1;j<n;j++)
            {
                if(arr[j]<=x)
                {
                    profit[i]++;
                    nxt[i]=j;
                }
                else
                {
                    break;
                }
            }

        }

        ///last item

        printf("Case %d: ",kk1);

    //    cout<<fun(0,0)<<endl;
        printf("%d\n",fun(0,0));

    }



}
