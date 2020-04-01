    #include<iostream>
    #include<stdio.h>
    #include<cmath>
    using namespace std;
    int main()
    {
        double pi,r,area;
        pi = 2 * acos (0.0) ;
        int T;
        cin>>T;
        for(int i=1;i<=T;i++)
        {
         cin>>r;
         area=r*r*(4-pi);
         printf("Case %d: %0.2lf\n",i,area);

        }


    return 0;
    }


