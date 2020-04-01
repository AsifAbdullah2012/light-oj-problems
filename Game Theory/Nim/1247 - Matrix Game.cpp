#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        int arra[55][55];
        int n,m;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&arra[i][j]);
            }
        }

        int ans[100];

        for(i=0;i<n;i++)
        {
            int sum = 0;
            for(j=0;j<m;j++)
            {
               // scanf("%d",&arra[i][j]);
                sum = sum + arra[i][j];
            }
            ans[i] = sum;
        }

        int fans = 0;

        for(i=0;i<n;i++)
        {
            fans = fans ^ (ans[i]);
        }

        printf("Case %d: ",kk1);

        if(fans)
        {
            printf("Alice\n");
        }
        else
        {
            printf("Bob\n");
        }
    }


}
