#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXI 200000

using namespace std;

int input[400005];
int segment[400005];
//int low,high,pos;

void construct(int input[],int segment[],int low,int high,int pos)
{
    if(low==high)
    {
        segment[pos]=input[low];
        return;
    }

    int mid=(low+high)/2;
    construct(input,segment,low,mid,2*pos);
    construct(input,segment,mid+1,high,2*pos+1);
    segment[pos]=min(segment[2*pos],segment[2*pos+1]);

   return;


}

int range(int segment[],int qlow,int qhigh,int low,int high,int pos)
{


    if(qlow>high || qhigh <low)
    {
        return MAXI;
    }



    if(low>=qlow && high<=qhigh)
    {
        return segment[pos];//overlap
    }



    int mid=(low+high)/2;

    return min(range(segment,qlow,qhigh,low,mid,2*pos),range(segment,qlow,qhigh,mid+1,high,2*pos+1));




}







int main()
{
    int i,j,k,n,m,t;
 //   cout<<"how many number in the array "<<endl;
    scanf("%d",&t);
    for(int kk=1;kk<=t;kk++){
  //  cout<<endl;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
      //  cin>>input[i];
        scanf("%d",&input[i]);
    }
    memset(segment,MAXI,sizeof(segment));
    construct(input,segment,0,n-1,1);


     printf("Case %d:\n",kk);
    for(j=0;j<m;j++)
    {
        int p1,p2;
    //    cin>>p1>>p2;

        scanf("%d %d",&p1,&p2);
        //Case 1:

  //      cout<<range(segment,p1,p2,1,n,1)<<endl;

        printf("%d\n",range(segment,p1,p2,1,n,1));


    }

    memset(input,0,sizeof(input));

    }



}

