#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define mx 500000000
#define mi 0

using namespace std;

int zero(int n)
{
    int ans=0;
    while(1)
    {
        if(n<5)
            break;
        ans=ans+(n/5);
        n=n/5;

    }

    return ans;

}


int main()
{
    int i,j,t,n;
    int lo,mid,hi;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%d",&n);
        lo=mi;
        hi=mx;


        while(lo<hi)
        {
            mid=(lo+hi)/2;
            if((hi-lo)<2)
                break;

          //  cout<<lo<<"  "<<hi<<"  "<<mid<<endl;

            if(zero(mid)>n)
            {
                hi=mid;
            }
            else
            {
                lo=mid;
            }


        }

        int pp;
        pp=zero(mid);
        printf("Case %d: ",kk1);
        if(pp==n)
        {
            int nn;
            nn=mid%5;
            nn=mid-nn;
            printf("%d\n",nn);

        }
        else
        {
           printf("impossible\n");

        }






    }



}

