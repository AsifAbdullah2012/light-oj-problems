#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>

using namespace std;
int n,m;
int arr[1009];

long long int check(long long int u)
{
    long long int cnt=1,i;
    long long int sum=0;
    for(i=0;i<m;i++)
    {
       sum=sum+arr[i];
   //    cout<<sum<<"  "<<cnt<<" "<<u<<endl;

       if(sum>u)
       {
           sum=arr[i];
           cnt++;
       }





    }





    return cnt;
}


int main()
{

   int i,j,k,t;
   scanf("%d",&t);
   for(int kk1=1;kk1<=t;kk1++)
   {
       scanf("%d %d",&m,&n);

       long long int sum=0,ans;
       long long int maxi=0;
       for(i=0;i<m;i++)
       {
           scanf("%d",&arr[i]);
           sum=sum+arr[i];
           if(arr[i]>maxi)
            maxi=arr[i];
       }

    //   sort(arr,arr+m);

       long long int mid,lo,hi;
       lo=maxi;
       hi=sum;

     //  cout<<lo<<"  "<<hi<<endl;

       while(lo<hi)
       {



           mid=(lo+hi)/2;
          int yy=check(mid);
      //     cout<<yy<<"  "<<mid<<endl;

           if(yy<=n)
           {
               hi=mid;
           }

           else
           {
               lo=mid+1;
           }






       }
       printf("Case %d: ",kk1);

       cout<<hi<<endl;



   }




}
