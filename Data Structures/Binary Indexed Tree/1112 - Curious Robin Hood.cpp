#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXI 2000000000
using namespace std;
//copy_king
long long int ans;

int input[400005];
struct nn{
    int sum;

}segment[400005];
void reset()
{
    int i;
    for(i=0;i<400005;i++)
    {
        segment[i].sum=0;
    }
}

void construct(int low,int high,int pos)
{
    if(low==high)
    {
        segment[pos].sum=input[low];
        return;
    }

    int mid=(low+high)/2;
    construct(low,mid,2*pos);
    construct(mid+1,high,2*pos+1);
    segment[pos].sum=segment[2*pos].sum+segment[2*pos+1].sum;
   return;


}

int ans1,kl;

void range1(int qlow,int qhigh,int low,int high,int pos)
{
    if(qlow>high || qhigh <low)
    {
        return ;
    }



    if(low>=qlow && high<=qhigh)
    {
        ans=ans+segment[pos].sum;
        return;

    }
    int mid=(low+high)/2;
    range1(qlow,qhigh,low,mid,2*pos);
    range1(qlow,qhigh,mid+1,high,2*pos+1);

}

void range(int qlow,int qhigh,int low,int high,int pos,int num2)
{


    if(qlow>high || qhigh <low)
    {
        return ;
    }



    if(low>=qlow && high<=qhigh)
    {
        if(num2==0)
        {
            ans1=segment[pos].sum;
            segment[pos].sum=0;
            input[low]=0;
        }
        else
        {

            segment[pos].sum=segment[pos].sum+kl;
            input[low]=input[low]+kl;
        }
        return;

    }

    int mid=(low+high)/2;
    range(qlow,qhigh,low,mid,2*pos,num2);
    range(qlow,qhigh,mid+1,high,2*pos+1,num2);
    segment[pos].sum=segment[2*pos].sum+segment[2*pos+1].sum;

}

int main()
{
    int i,j,k,n,m,t;

    scanf("%d",&t);
    for(int kk=1;kk<=t;kk++){

    reset();

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }
    construct(0,n-1,1);
     printf("Case %d:\n",kk);
     int p1,p2,p3;
    for(j=0;j<m;j++)
    {
        int mm;
        scanf("%d",&mm);
        if(mm==1)
        {
            scanf("%d",&p2);
            range(p2,p2,0,n-1,1,0);
            printf("%d\n",ans1);
        }

        else if(mm==2)
        {
            scanf("%d %d",&p1,&kl);
            range(p1,p1,0,n-1,1,1);

        }

        else
        {
            scanf("%d %d ",&p1,&p2);
            ans=0;
            range1(p1,p2,0,n-1,1);
            printf("%lld\n",ans);


        }






    }





    }


}

