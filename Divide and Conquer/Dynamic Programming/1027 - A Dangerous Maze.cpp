    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <algorithm>
    #include <cmath>
    #include <queue>
    #include <stack>
    #include <vector>
    #include <set>
    #include <map>

    using namespace std;


    int main()
    {

        int i,j,k,t,n,x,e1,e2,s1,s2;
        cin>>t;

        for(int kk=1;kk<=t;kk++)
        {
           // cout<<endl;
            cin>>n;
            e1=1;
            e1=e1*n;
            e2=0;
            s1=0;
            s2=0;

         //   Case 1: 1/1

            for(i=0;i<n;i++)
            {
                cin>>x;
                if(x<0)
                {
                    e2++;
                    s1=s1+fabs(x);
                }

                else if(x>=0)
                {
                    s1=s1+x;

                }



            }



            if(e2==e1)
            {
                cout<<"Case "<<kk<<": "<<"inf"<<endl;

            }

            else
            {
                e1=e1-e2;
                int  s =__gcd (e1, s1);
                e1=e1/s;
                s1=s1/s;

                cout<<"Case "<<kk<<": "<<s1<<"/"<<e1<<endl;

            }





        }






    }

