#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long
#define maxi 1000000000000
//accepted


using namespace std;

vector<ll>vec;
set<ll>myset;
vector<ll>ansf;


ll gen(ll sum)
{

    if(sum>0&&sum<maxi)
        vec.push_back(sum);

    if(sum>maxi)
     return 0;

    gen(sum*10+4);
    gen(sum*10+7);


}

ll gen2(ll idx,ll summ)
{
    if(summ>maxi)
        return 0;
    if(summ>1&&summ<maxi)
    {
        myset.insert(summ);
    }

    if(idx>=vec.size())
    {
        if(summ>1&&summ<maxi)
        {
            myset.insert(summ);
        }
        return 0;

    }

    if(summ<=maxi/vec[idx])
    gen2(idx,summ*vec[idx]);
    if(summ<=maxi/vec[idx])
    gen2(idx+1,summ*vec[idx]);
    if(summ<=maxi/vec[idx])
    gen2(idx+1,summ);

  //  return ;




}


int main()
{
    gen(0);
    sort(vec.begin(),vec.end());
    gen2(0,1);

     for (set<ll>::iterator it=myset.begin(); it!=myset.end(); ++it)
    ansf.push_back(*it);


    int i,j,k,l,t;
    ll a1,b2;
    scanf("%d",&t);

    for(int kk1=1;kk1<=t;kk1++)
    {

    scanf("%lld %lld",&a1,&b2);
     //ansf.clear();


    //Case 1: 0
    printf("Case %d: ",kk1);

    cout<<upper_bound(ansf.begin(),ansf.end(),b2)-lower_bound(ansf.begin(),ansf.end(),a1)<<endl;



    }






}

