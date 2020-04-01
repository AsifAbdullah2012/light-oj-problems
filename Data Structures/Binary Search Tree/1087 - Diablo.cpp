#include<bits/stdc++.h>
#define ll long long int

using namespace std;


struct info
{
    ll cnt,val;
}segment[4*(100000+50000+8)+8];

ll in[100000+50000+8];
ll in1[100000+50000+8];


void construct(long long int low,long long int high,long long int pos)
{
    if(low==high)
    {
       // cout<<pos<<"   "<<in[low]<<endl;
        segment[pos].cnt=in[low];
        segment[pos].val=in1[low];
        return;
    }

    long long int mid=(low+high)/2LL;
    construct(low,mid,2LL*pos);
    construct(mid+1LL,high,2LL*pos+1LL);
    segment[pos].cnt=segment[2LL*pos].cnt+segment[2LL*pos+1LL].cnt;
   return;


}

///update segment

ll update(long long int node, long long int b, long long int e, long long int i, long long int newvalue)
{

  //  cout<<b<<"--->"<<e<<"  "<<node<<endl;
   // if (i > e || i < b)
   //     return;
    if (b==e) {
     //   cout<<"ass"<<endl;
        segment[node].cnt =newvalue;
        printf("%lld\n",segment[node].val);
        return b;
    }
    long long int Left = node * 2LL;
    long long int Right = node * 2LL + 1LL;
    long long int mid = (b + e) / 2LL;
    ///work
    ll lf,rt;
    lf = segment[Left].cnt;
    rt = segment[Right].cnt;

    if(i<=lf)
    update(Left, b, mid, i, newvalue);
    else
    update(Right, mid + 1LL, e, i-lf, newvalue);
   // segment[node].cnt = segment[Left].cnt + segment[Right].cnt;
}

void update1(long long int node, long long int b, long long int e, long long int i, long long int newvalue,ll valu)
{

    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
     //   cout<<node<<endl;
        segment[node].cnt =newvalue;
        segment[node].val= valu;
        return;
    }
    long long int Left = node * 2LL;
    long long int Right = node * 2LL + 1LL;
    long long int mid = (b + e) / 2LL;
    update1(Left, b, mid, i, newvalue,valu);
    update1(Right, mid + 1LL, e, i, newvalue,valu);
    segment[node].cnt = segment[Left].cnt + segment[Right].cnt;
}

void update2(long long int node, long long int b, long long int e, long long int i, long long int newvalue)
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
    update2(Left, b, mid, i, newvalue);
    update2(Right, mid + 1LL, e, i, newvalue);
    segment[node].cnt = segment[Left].cnt + segment[Right].cnt;
}






int main()
{
    ll i,j,n,t,q,num;
    scanf("%lld",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%lld %lld",&n,&q);

        ll mx=n+q;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&num);
            in1[i] = num;
        }
        getchar();



        for(i=0;i<mx;i++)
        {
            if(i<n)
            {
                in[i]=1;
            }
            else
            {
                in[i]=0;
            }
        }

        construct(0,mx-1,1);


        ll point = n;

        char c;
        int num1;

        int mycnt=n;

        printf("Case %d:\n",kk1);

        for(i=0;i<q;i++)
        {
            scanf("%c",&c);
           // getchar();
            //cin>>c;
            scanf("%d",&num1);
           // printf("%c\n",c);
             getchar();

            if(c=='c')
            {
           //     cout<<"asas"<<endl;
                if(num1>mycnt)
                {
                    printf("none\n");
                }
                else
                {
                    mycnt--;
                    ll op;
                    op = update(1,0,mx-1,num1,0);
                    update2(1,0,mx-1,op,0);

                }
            }
            else
            {
        //        cout<<"pp"<<endl;
                mycnt++;
                update1(1,0,mx-1,point,1,num1);
                point++;
            }
        }






    }



}

