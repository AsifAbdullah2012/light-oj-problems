#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iomanip>
#define PI 3.14159265359
 
using namespace std;
 
int main()
{
    int i,j,k,l,n,t,m,nn,mm;
    double ss,ss1,ss2;
    char c;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        cin>>n>>c>>m;
        nn=n;
        mm=m;
        n=n*n;
        m=m*m;
        ss=sqrt(n+m);
        ss=ss/2.0;
        ss2=ss;
        ss=ss*ss;
        ss=ss*2;
        ss1=(ss-m);
        ss1=ss1/(2*(ss2*ss2));
        ss1=acos(ss1);
        ss1=2*ss2*ss1;
        ss1=ss1+2*nn;
        ss1=400.00/ss1;
        printf("Case %d: ",kk1);
        cout<<setprecision(15)<<ss1*nn<<" "<<setprecision(15)<<ss1*mm<<endl;
 
 
 
    }
 
 
 
 
 
}
