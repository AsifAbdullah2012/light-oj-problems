    //   hercules jupiter(User)

    #include<iostream>
    #include<stdio.h>
    #include<string.h>
    #include<math.h>
    #define PI acos(-1)

    using namespace std;


    int main()
    {

        int i,j,k,l,n,t;
        double AB,AC,BC,ra,s,ar,h,ha,abc,acb,bac,ADE,BDEC,AD,ra2;
        cin>>t;
        for(i=1;i<=t;i++)
        {
            cin>>AB>>AC>>BC>>ra;
            s=(AB+AC+BC)/2.0;
            ar=s*(s-AB)*(s-AC)*(s-BC);
            ar=sqrt(ar);
            h=(2*ar)/BC;
            abc=((AB*AB)+(BC*BC)-(AC*AC))/(double)(2*AB*BC);
            acb=((AC*AC)+(BC*BC)-(AB*AB))/(double)(2*BC*AC);
            bac=((AB*AB)+(AC*AC)-(BC*BC))/(double)(2*AB*AC);
            abc=acos(abc);
            acb=acos(acb);
            bac=acos(bac);

           // cout<<cos(acb)<<" "<<abc<<"  "<<bac<<endl;
           // AD=81.6496580;
             double low,mid,high;
             low=0;
             high=AB;
             mid=(low+high)/2.0;
             double pp=1.0;

             while(low<high){

                 //   cout<<low<<" "<<mid<<"  "<<high<<endl;

            //AD=mid;
            mid=(low+high)/2.0;
                       //     cout<<low<<" "<<mid<<"  "<<high<<" "<<ra<<" "<<ra2<<endl;
            AD=mid;
            ADE=(.5)*((cos(abc)*AD)+((tan(abc)*cos(abc)*AD)/(double)(tan(acb))))*(tan(abc)*cos(abc)*AD);
            BDEC=(.5)*(h-(tan(abc)*cos(abc)*AD))*((cos(abc)*AD+((tan(abc)*cos(abc)*AD)/(double)(tan(acb))))+BC);

       //     cout<<AD<<" "<<pp<<endl;
            ra2=(ADE/(double)BDEC);

             if(fabs(AD-pp)<.00000001){
                //cout<<mid<<endl;
                printf("Case %d: %0.10lf\n",i,mid);
                break;

             }

             if(ra2>ra){
                high=mid;

             }

             if(ra2<=ra){
                low=mid;

             }


           pp=AD;

         //  cout<<ADE<<"  "<<BDEC<<endl;


           }


        }




    }


