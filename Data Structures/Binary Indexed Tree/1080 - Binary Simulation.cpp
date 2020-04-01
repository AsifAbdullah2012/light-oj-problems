#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXI 200000

using namespace std;
//copy_king
int ans;
//int input[400005];
int segment[400005];
//int low,high,pos;

void construct(int low,int high,int qlow,int qhigh,int pos,int num)
{
     if(qlow>high || qhigh <low)
    {
        return;
    }

    if(low>=qlow && high<=qhigh)
    {
         ans=num+segment[pos];
         return;
         //overlap
    }

    int mid=(low+high)/2;
    construct(low,mid,qlow,qlow,2*pos,num+segment[pos]);
    construct(mid+1,high,qlow,qlow,2*pos+1,num+segment[pos]);
  //  segment[pos]=min(segment[2*pos],segment[2*pos+1]);

 //  return;


}

void range(int segment[],int qlow,int qhigh,int low,int high,int pos)
{


    if(qlow>high || qhigh <low)
    {
        return ;
    }



    if(low>=qlow && high<=qhigh)
    {
         segment[pos]++;
         return;
         //overlap
    }



    int mid=(low+high)/2;

    range(segment,qlow,qhigh,low,mid,2*pos);
    range(segment,qlow,qhigh,mid+1,high,2*pos+1);




}







int main()
{
    int i,j,k,n,m,t,q,a,b,c;
    char ch1[400006],ch2[3];

 //   cout<<"how many number in the array "<<endl;
    scanf("%d",&t);
    for(int kk=1;kk<=t;kk++){
  //  cout<<endl;
    printf("Case %d:\n",kk);
    memset(segment,0,sizeof(segment));
    scanf("%s",ch1);
    n=strlen(ch1)-1;

    scanf("%d",&q);

    for(int pp1=1;pp1<=q;pp1++)
    {

        scanf("%s",ch2);

        if(ch2[0]=='I')
        {
            scanf("%d %d",&a,&b);
            a--;
            b--;

            range(segment,a,b,0,n,1);

        }
       else
       {
           scanf("%d",&a);
           ans=0;
           a--;
           b=a;
           //query(1,0,n,a,b,0);//int low,int high,int qlow,int qhigh,int pos,int num)
           construct(0,n,a,a,1,0);

           if(ans%2==0)
            {
            printf("%c\n",ch1[a]);
            }

           else
           {
               if(ch1[a]=='0')
                printf("1\n");
            else
                printf("0\n");
           }




       }


    }


    //'''''''''''''''''''''''''''''''''''''''''''''


    }

 return 0;

    }


