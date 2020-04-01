#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        int arra1[109],arra2[109];
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arra1[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&arra2[i]);
        }
        int ans = 0;
        for(i=0;i<n;i++)
        {
           ans = ans ^ (arra2[i]-arra1[i]-1);
        }
        printf("Case %d: ",kk1);
        if(ans)
        {
            printf("white wins\n");
        }
        else
        {
            printf("black wins\n");
        }
    }


}
