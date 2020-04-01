    #include<iostream>
    #include<stdio.h>
    #include<string.h>
    #include<math.h>

    using namespace std;

    int input[1000];
    double result[1000];
    bool visited[1000];

    int n;


    double dp(int pos)
    {

        if(pos>=n)
            return 0;

        if(pos+1==n)
            return input[pos];

        if(visited[pos])
            return result[pos];

        visited[pos]=true;

            double ret;


        double b;
        if(n-pos-1>= 6)
        {
            b = 6;
        }
        else
        {
            b = n-pos-1;
        }

        ret = input[pos];

        for(int ii=1;ii<=6;ii++)
        {
            ret = ret + dp(pos + ii)/b;
            result[pos]=ret;
        }

        return ret;

        //return result[n-1];








    }




    int main()
    {

        int i,j,k,t,m;
        cin>>t;
        for(int kk=1;kk<=t;kk++)
        {

             memset(visited,false,sizeof(visited));
             memset(result,false,sizeof(result));

            cin>>n;

            for(i=0;i<n;i++)
            {
                cin>>input[i];

            }

            printf("Case %d: %.9lf\n", kk, dp(0));









        }








    }


