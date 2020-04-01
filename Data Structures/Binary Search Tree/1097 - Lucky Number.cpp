#include<bits/stdc++.h>

using namespace std;

///100000 th number is 1429431 == 1429600
///so make a tree with 1429600 nodes and update and query among them

struct info{
            int val,cnt;

}segment[4*1429600];///number of node will be tensto 3 time of my array

///save answer in array ans higest 100000 elements

int ans[100000+8];

///construction my segment tree

void construct(int low,int high,int pos)
{
    if(low==high)
    {
        if(low%2==1)
        segment[pos].cnt=1;
        else
        segment[pos].cnt=0;

        segment[pos].val=low;
   //     cout<<pos<<"---->"<<segment[pos].cnt<<endl;
        return;
    }

    int mid=(low+high)/2;
    construct(low,mid,2*pos);
    construct(mid+1,high,2*pos+1);
    segment[pos].cnt=segment[2*pos].cnt+segment[2*pos+1].cnt;
   return;


}

///finding the index of my ith element


int update(int node,int b,int e,int i)
{
   // cout<<b<<"  "<<e<<endl;

    if (b==e) {

        return b;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    ///work
    int lf,rt;
    lf = segment[Left].cnt;
    rt = segment[Right].cnt;

    if(i<=lf)
    update(Left, b, mid, i);
    else
    update(Right, mid + 1, e, i-lf);
}

void update2(int node,int b,int e,int i)
{
   // cout<<b<<"  "<<e<<endl;

    if (b==e) {

        segment[node].cnt=0;
        return ;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    ///work
    int lf,rt;
    lf = segment[Left].cnt;
    rt = segment[Right].cnt;

    if(i<=lf)
    update2(Left, b, mid, i);
    else
    update2(Right, mid + 1, e, i-lf);
    segment[node].cnt=segment[Left].cnt+segment[Right].cnt;

}




///putting zero in ith index of tree

void update3(long long int node, long long int b, long long int e, long long int i, long long int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        segment[node].cnt =segment[node].cnt+newvalue;
        return;
    }
    long long int Left = node * 2LL;
    long long int Right = node * 2LL + 1LL;
    long long int mid = (b + e) / 2LL;
    update3(Left, b, mid, i, newvalue);
    update3(Right, mid + 1LL, e, i, newvalue);
    segment[node].cnt = segment[Left].cnt + segment[Right].cnt;
}




int main()
{

    ///precalulation

    ///cout<<"check"<<endl;


    int i,j,k;
    construct(1,1429600,1);
    ans[1]=1;
    ///process i=2 to 1429600

   /// cout<<"check"<<endl;


    for(i=2;i<=100000+9;i++)
    {
        int fdex;
        fdex = update(1,1,1429600,i);


        ans[i]=fdex;

     //
     //     if(i==2)
     //   cout<<fdex<<"  "<<fdex<<endl;

        int lmt;
        lmt = (1429600/fdex)*fdex;
        int pp;
        for(j=lmt;j>=fdex;j=j-fdex)
        {
           update2(1,1,1429600,j);

        }

    }

    ///process end

    int t,n;
    scanf("%d",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%d",&n);
        printf("Case %d: ",kk1);
        printf("%d\n",ans[n]);
    }




}

