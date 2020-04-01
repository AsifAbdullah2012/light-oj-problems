#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <iomanip>

#define pi acos(-1)


using namespace std;

//const double EPS = 1e-10;

int main()
{

     int i,j,k,t;
     double L,n,c,LL;
     scanf("%d",&t);

//     (1+n*C)*L

     for(int kk1=1;kk1<=t;kk1++)
     {
         cin>>L>>n>>c;
         LL=(1+n*c)*L;

       //  cout<<L<<"-->"<<LL<<endl;

         double low,mid,hi;
         low=0.00;
         hi=(acos(-1)/2.000);
         int cnt=0;
         double decid;

         while(1)
         {
             if(cnt==32)
                break;

             cnt++;
             mid=(low+hi)/2.00;
             decid=L/2.00/sin(mid);
             decid=decid*2.00*mid;
             if(decid>LL)
             {

                 hi=mid;
             }
             else
             {

                 low=mid;
             }

             }


             double ans;
             ans=0.00;


             ans=L/2/sin(mid);
             ans=ans-(ans*cos(mid));


             printf("Case %d: %.8lf\n", kk1, ans);





     }





}
