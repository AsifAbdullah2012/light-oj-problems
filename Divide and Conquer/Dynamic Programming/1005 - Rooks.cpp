    #include<iostream>
    #include<string.h>
    #include<stdio.h>
    #include<math.h>
    #define ll unsigned long long


    using namespace std;

    int main()
    {

        int i,j,l,t;
        scanf("%d",&t);
        ll n,k;
        ll ans;

        for(int kk1=1;kk1<=t;kk1++)
        {
            scanf("%llu %llu",&n,&k);
            ans=1;
            printf("Case %d: ",kk1);
            if(n<k)
            {
                printf("0\n");
                continue;
            }

            ll oo;

            for(oo=1;oo<=k;oo++)
            {
                ans=ans*(n*n)/oo;
                n--;
            }

            cout<<ans<<endl;

        }




    }


