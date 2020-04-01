#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long int in[100000+8];
long long int fx[100000+8];
long long int segment[4*100000+8];

map<long long int,long long int>mymap;

void reset()
{
    long long int i;
    for(i=0;i<400005;i++)
    {
        segment[i]=0;
    }
}

void construct(long long int low,long long int high,long long int pos)
{
    if(low==high)
    {
        segment[pos]=0LL;
        return;
    }

    long long int mid=(low+high)/2LL;
    construct(low,mid,2LL*pos);
    construct(mid+1LL,high,2LL*pos+1LL);
    segment[pos]=segment[2LL*pos]+segment[2LL*pos+1LL];
   return;


}

long long int query(long long int node, long long int b, long long int e, long long int i, long long int j)
{
    if (i > e || j < b)
        return 0LL;
    if (b >= i && e <= j)
        return segment[node];
    long long int Left = node * 2LL;
    long long int Right = node * 2LL + 1LL;
    long long int mid = (b + e) / 2LL;
    long long int p1 = query(Left, b, mid, i, j);
    long long int p2 = query(Right, mid + 1LL, e, i, j);
    return (p1 + p2)%mod;
}

void update(long long int node, long long int b, long long int e, long long int i, long long int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        segment[node] =(segment[node] + newvalue)%mod;
        return;
    }
    long long int Left = node * 2LL;
    long long int Right = node * 2LL + 1LL;
    long long int mid = (b + e) / 2LL;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1LL, e, i, newvalue);
    segment[node] = (segment[Left] + segment[Right])%mod;
}


int main()
{
    long long int i,j,k,t,n;
    scanf("%lld",&t);

    for(long long int kk1=1LL;kk1<=t;kk1++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&in[i]);
        //    in[i]=i+1LL;
            fx[i]=in[i];
        }

        sort(fx,fx+n);
        long long int cnt=1LL;
        mymap.clear();

        for(i=0;i<n;i++)
       {
       //     cout<<fx[i]<<endl;
        }

        for(i=0;i<n;i++)
        {
           // cout<<mymap[fx[i]]<<"  "<<cnt<<endl;
            if(mymap[fx[i]]==0LL)
            {
                mymap[fx[i]]=cnt;
                cnt++;
            }

        }

        for(i=0;i<n;i++)
        {
            fx[i]=mymap[in[i]];
        }



        construct(0,cnt-1,1);

        long long int ans=0;



        for(i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                update(1,0,cnt-1,fx[i]-1,1);
                ans++;
            }
            else
            {
                long long int lo,hi;
                lo=fx[i]+1;
                hi=cnt;
                lo--;
                hi--;
                long long int temp;
                temp=query(1,0,cnt-1,lo,hi);
                ans=(ans+temp)%mod;
                ans=(ans+1)%mod;
                update(1,0,cnt-1,fx[i]-1,(temp+1)%mod);
           //     cout<<temp<<endl;


            }

         //   cout<<fx[i]<<endl;


        }

       //  cout<<ans<<endl;
        printf("Case %lld: ",kk1);
        printf("%lld\n",ans);

    }


}

