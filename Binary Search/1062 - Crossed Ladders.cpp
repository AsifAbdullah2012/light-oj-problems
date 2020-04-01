#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#define ERR .000000001

using namespace std;

int main()
{

int i,j,k,l,n,m,t,tt;
double x,y,c;
scanf("%d",&t);
for(int kk1=1;kk1<=t;kk1++)
{
  //  scanf("%lf %lf %lf",&x,&y,&c);
    cin>>x>>y>>c;
    tt=min(x,y);
 //   cout<<tt<<endl;
    double lo,hi,mid;
    lo=0.00;
    hi=tt;
    double ck=20.00;
    double v1,v2,v3,c1,ans;
    c1=c;

    while(1)
    {
        mid=(lo+hi)/2.00;
        v1=x*x-mid*mid;
        if(v1<0)
            continue;
        v1=sqrt(v1);
        v1=1.00/v1;
        v2=y*y-mid*mid;
        if(v2<0)
            continue;
        v2=sqrt(v2);
        v2=1.00/v2;
        v3=v1+v2;
        v3=1.00/v3;


        if((hi-lo)<ERR)
        {
            ans=mid;
            break;
        }

        if(v3>c1)
        {

           lo=mid;
        }
        if(v3<c1)
        {
            hi=mid;
        }


   }
    printf("Case %d: ",kk1);
    cout<<setprecision(10)<<ans<<endl;



}








}

