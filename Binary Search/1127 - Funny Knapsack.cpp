#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int i,j,t,k;
    long long int arr1[1<<16];
    long long int arr2[1<<16];
    int item[35];
    long long int n,w;
    long long int len1,len2,pp;
    long long int yy;

    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%lld %lld",&n,&w);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&item[i]);
        }
        len1=0;
        len2=0;
        arr1[0]=0;
        arr2[0]=0;

        len1++;
        len2++;

        for(i=0;i<n/2;i++)
        {
            pp=len1;
            for(j=0;j<pp;j++)
            {
                yy=w-arr1[j];
                if(item[i]>yy)
                    continue;
                arr1[len1]=arr1[j]+item[i];
                len1++;

            }

        }

        long long int ans=0;
        long long int *hom,*up;
        hom=&arr1[0];
        sort(arr1,arr1+len1);

        for(i=n/2;i<n;i++)
        {
            pp=len2;
            for(j=0;j<pp;j++)
            {
                yy=w-arr2[j];
                if(item[i]>yy)
                    continue;
                arr2[len2]=arr2[j]+item[i];
                len2++;

            }

        }


       for(i=0;i<len2;i++)
       {
           yy=w-arr2[i];
           up=upper_bound(arr1,arr1+len1,yy);
           ans=ans+(up-hom);

       }
       printf("Case %d: ",kk1);
       cout<<ans<<endl;


    }




}

