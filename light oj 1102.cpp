///stars and bars problem
///how to seperate n stars using k-1 bars
 
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
 
using namespace std;
ll fact[2000000+7];
 
// To compute x raised to power y under modulo m
ll power(ll x, unsigned ll y, unsigned ll m);
 
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
 
int main()
{
    ll i,j,k,n;
    fact[0]=1;
    for(i=1;i<=2000000;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    int t;
    scanf("%d",&t);
    for(int kk1=1;kk1<=t;kk1++){
 
    scanf("%ld %ld",&n,&k);
 
    ll ans1,ans2;
    ans1 = fact[n+k-1];
    ans2 = (fact[k-1]*fact[n])%mod;
    ans2 = modInverse(ans2,mod);
    ans1 = (ans1*ans2)%mod;
    if(ans1<0)
    {
        ans1=(ans1+mod)%mod;
    }
    printf("Case %d: ",kk1);
    printf("%ld\n",ans1);
 
 
    }
 
}
