#include<bits/stdc++.h>
#define ll long long
#define mod 100000007
#define mx 10000000000

using namespace std;

ll valus[1000000+8];
ll fact[2000000+8];
ll cnt;
ll power(ll x, unsigned ll y, unsigned ll m);

///catalan numer
/// (2n)!/((n+1)!*n!) follows the equation 1 1 2 4 .... for the values 0 1 2 3 ....



void gen()
{
    ll i,j;
    ll limt;
    limt = sqrt(mx);
    ll num;
    cnt=0;
    for(i=2;i<=limt;i++)
    {
        num = i*i;
        while(num<=mx)
        {
            valus[cnt++]=num;
            num=num*i;
        }

    }

    sort(valus,valus+cnt);
    cnt=unique(valus,valus+cnt)-valus;


}


// To compute x raised to power y under modulo m

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}


// Function to find modular inverse of a under modulo m
// Assumption: m is prime
ll modInverse(ll a, ll m)
{
    ll g = gcd(a, m);
    ll ans;
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
     ans = power(a, m-2, m);
    }
}

// To compute x^y under modulo m
ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

// Function to return gcd of a and b

void call()
{
    fact[0]=1;
    ll i;
    for(i=1;i<2000000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }

}

int main()
{
    ll i,j,k,n,t;
    gen();
    call();
    ll a,b;
    ll ans1,ans2;
    scanf("%lld",&t);
    for(int kk1=1;kk1<=t;kk1++)
    {
        //
        //cin>>a>>b;
        scanf("%lld %lld",&a,&b);
        ll  lo,hi;
        lo = lower_bound(valus,valus+cnt,a)-valus;
        hi = upper_bound(valus,valus+cnt,b)-valus;
        n = hi-lo;
        printf("Case %d: ",kk1);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        ans1 = (fact[n+1]*fact[n])%mod;
        ans1 = modInverse(ans1,mod);
        ans1 = (ans1*fact[2*n])%mod;

        printf("%lld\n",ans1);

    }





}


