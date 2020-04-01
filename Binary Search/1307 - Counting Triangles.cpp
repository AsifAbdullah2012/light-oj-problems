#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{

    int i,j,k,t,n,cot,pp,ll;
    int arr[3000];
    int *hom,*low,*up;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        int ans,mid,ans1,l,r;
        ans=0;
        ans1=0;

        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {

                  l=j+1;
                  r=n-1;
                  pp=arr[i]+arr[j];
                  ans1=l-1;

                  while(l<=r)
                  {
                      mid=(l+r)/2;
                      if(arr[mid]<pp)
                      {
                          ans1=mid;
                          l=mid+1;
                      }
                      else
                      {
                          r=mid-1;
                      }


                  }

                  ans=ans+ans1-j;

            }

        }

        printf("Case %d: ",kk1);
        printf("%d\n",ans);



    }





}

