#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<algorithm>
#include<map>
#define PI 3.14159265359
#define COR .0000000001

using namespace std;

int main()
{

    double a;


    int i,j,k,l,n,m,t;
    double R,r;
    cin>>t;

    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%lf %d",&R,&n);
        double mid,lo,hi;
        lo=0.00;
        hi=R;

        double kk=20.00;

        while(1)
        {

            if(kk<COR)
            {
                break;
            }

      //      cout<<mid<<endl;
            mid=(lo+hi)/2.00;
            a=asin(mid/(R-mid));
            a=(a*180.000)/PI;
            a=a*2.00;

            double mm;
            mm=360.00/a;

            if((int)mm>=n)
            {


                lo=mid;
                kk=hi-mid;

            }

            else
            {
                hi=mid;
                kk=mid-lo;

            }





        }
        printf("Case %d: ",kk1);
        cout<<setprecision (9)<<mid<<endl;







    }








}

