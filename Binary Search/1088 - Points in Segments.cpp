#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;
int segment[100008];

int main()
{
    int t,i,j,m,n,a,b;
    int *hook,*low,*high;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&segment[i]);
        }
        hook=&segment[0];
        printf("Case %d:\n",kk1);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            low=lower_bound(segment,segment+n,a);
            a=low-hook;
            high=lower_bound(segment,segment+n,b+1);
            b=high-hook;

            printf("%d\n",(b-a));
        }




    }

    return 0;

}


