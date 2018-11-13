    #include<iostream>
    #include<stdio.h>
    #include<string.h>
     
    using namespace std;
    int arr[1009],N,K;
     
    bool call(int u)
    {
        int i,cnt,sum;
        cnt=0;
        sum=0;
        for(i=0;i<=N;i++)
        {
            sum=sum+arr[i];
            if(sum>u)
            {
                cnt++;
                sum=arr[i];
            }
     
        }
     
        if(cnt<=K)
            return 1;
     
        else
            return 0;
     
     
    }
     
    int main()
    {
        int i,j,k,t,sum,maxi,ans;
     
        scanf("%d",&t);
     
        for(int kk1=1;kk1<=t;kk1++)
        {
            scanf("%d %d",&N,&K);
            maxi=0;
            sum=0;
            for(i=0;i<=N;i++)
            {
                scanf("%d",&arr[i]);
                if(arr[i]>maxi)
                    maxi=arr[i];
     
                sum=sum+arr[i];
            }
     
     
     
            int mid,hi,lo;
            lo=maxi;
            hi=sum;
        //    cout<<sum<<" "<<lo<<endl;
     
            while(lo<=hi)
            {
     
                mid=(lo+hi)/2;
     
          //      cout<<mid<<endl;
     
                if(call(mid)){
                    hi=mid-1;
                    ans=mid;
     
                }
     
                else
                {
                    lo=mid+1;
     
     
                }
     
     
     
            }
     
          //  cout<<ans<<endl;
     
          printf("Case %d: ",kk1);
     
          sum=0;
          cout<<ans<<endl;
          int cnt=0;
          int jj=K+1;
     
         for(i = j = sum = 0; i <= N; i++) {
                sum += arr[i];
                if(sum > ans || K-j > N-i) {
                    sum -= arr[i];
                    printf("%d\n", sum);
                    j++;
                    sum = arr[i];
                }
            }
            printf("%d\n", sum);
     
     
     
     
     
     
        }
     
     
     
     
     
     
    }
     
