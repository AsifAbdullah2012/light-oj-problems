#include <sstream>
    #include <queue>
    #include <set>
    #include <map>
    #include <cstdio>
    #include <cstdlib>
    #include <cctype>
    #include <cmath>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <bitset>
    #include <list>
    #include <string.h>
    using namespace std;
    #define print1(a)    cout<<a<<endl
    #define print2(a,b) cout<<a<<" "<<b<<endl
    #define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
    #define oo          (1<<30)
    #define PI          3.141592653589793
    #define pi          (2*acos(0))
    #define ERR        1e-5
    #define PRE        1e-8
    #define SZ(s)      (int)s.size()
    #define LL           long long
    #define ISS         istringstream
    #define OSS        ostringstream
    #define VS          vector<string>
    #define VI          vector<int>
    #define VD          vector<double>
    #define VLL         vector<long long>
    #define SII         set<int>::iterator
    #define SI          set<int>
    #define mem(a,b)    memset(a,b,sizeof(a))
    #define fr(i,a,b)   for(i=a;i<=b;i++)
    #define frn(i,a,b)  for(i=a;i>=b;i--)
    #define fri(a,b)    for(i=a;i<=b;i++)
    #define frin(a,b)   for(i=a;i>=b;i--)
    #define frj(a,b)    for(j=a;j<=b;j++)
    #define frjn(a,b)   for(j=a;j>=b;j--)
    #define frk(a,b)    for(k=a;k<=b;k++)
    #define frkn(a,b)   for(k=a;k>=b;k--)
    #define frl(a,b)    for(l=a;l<=b;l++)
    #define frln(a,b)   for(l=a;l>=b;l--)
    #define EQ(a,b)     (fabs(a-b)<ERR)
    #define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
    #define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
    #define sqr(a)      ((a)*(a))
    #define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)
    #define typing(j,b) typeof((b).begin()) j=(b).begin();
    #define BE(a)       a.begin(),a.end()
    #define rev(a)      reverse(BE(a));
    #define sorta(a)    sort(BE(a))
    #define pb          push_back
    #define popb        pop_back
    #define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
    #define makeint(n,s)  istringstream(s)>>n
    #define inpow(a,x,y) int i; a=x;fri(2,y)  a*=x
    #define cntbit(mask) __builtin_popcount(mask)

    #define mo          1000
    #define inf         1000000000
    //only adj and w matrix should be changed
    //minimum capacity should be 0(initially given)
    //complexity V^2E(95 percent time faster) (for sparse graph)
    typedef queue<int>vi;
    VI adj[mo];//input
    int w[mo][mo];//input
    VI sinklist;//adj[sink]
    bool col[mo];
    int par[mo];//par and col for parent and visited respectively
    int totflow,flow;//flow related variables.(not needed normally)

    void updategraph(int source, int sink) //flow is never infinity here
    {
        int prev,next;
        next=sink;
        flow=inf;
        //printf("fsd");
        while(par[next]>-1)
        {
            //print2(next,par[next]);
            prev=par[next];
            flow=min(flow,w[prev][next]);
            next=prev;
        }
        //printf("fds");
        next=sink;
        while(par[next]>-1)
        {
            prev=par[next];
            w[prev][next]-=flow;
            w[next][prev]+=flow;
            next=prev;
        }
    }


    bool augment_path(int source,int sink) // return true if there is positive flow
    {
        queue<int>q;
        q.push(source);
        mem(par,-1);
        mem(col,false);
        col[source]=true;
        int prev,next;
        bool cnt=true;
        while(q.size()&&cnt)
        {
            int i;
            prev=q.front();
            q.pop();
            //print1(prev);
            for(i=0;i<SZ(adj[prev]);i++)
            {
                next=adj[prev][i];
                //print1(next);
                if(!col[next]&&w[prev][next]>0)
                {
                    col[next]=true;
                    par[next]=prev;
                    if(next==sink) continue;
                    q.push(next);
                }
            }
        }

        return par[sink]!=-1;
    }

    void maxflow(int source,int sink)
    {
        totflow=0;
        sinklist=adj[sink];
        while(augment_path(source,sink))
        {
            for(int i=0;i<sinklist.size();i++)
            {
                int u = sinklist[i];
                if(!col[u] || w[u][sink]<=0) continue;
                par[sink]=u;
                updategraph(source,sink);
                totflow+=flow;
            }
        }
        return;
    }

    void makeedge(int a,int b,int c)
    {
       adj[a].pb(b);
       adj[b].pb(a);
       w[a][b]=c;
       w[b][a]=0;
    }


    int main()
    {
        int n,m;
        int e,k;
        int yy;
         int pp,j,ppq;
       // int seta[102];
      //  int setb[102];
         int yyp[102];
        int t;
        scanf("%d",&t);

        for(int kk1=1;kk1<=t;kk1++)
        {

            cin>>n;


            int arr[102];

            int i;
            int a,b,c;
            for(i=0;i<n;i++)
            {
                scanf("%d",&pp);
                arr[i]=pp;
            }

            int maxi=-10000;

            scanf("%d",&m);
            for(i=0;i<m;i++)
            {
                scanf("%d",&pp);
                maxi=max(maxi,pp);
                yyp[i]=pp;

            }
            int md;



            mem(w,0);
            yy=n+m+2;
            fr(i,0,yy)
            adj[i].clear();

            int mdn;
            for(i=0;i<n;i++)
            {
                pp=arr[i];
            //    cout<<pp<<" ";
                for(j=1;;j++)
                {
                    if((pp*j)>maxi)
                        break;
                    ppq=pp*j;

                    for(k=0;k<m;k++)
                    {
                        if(yyp[k]==ppq)
                        {
                            makeedge(i+1,k+1+n,1);
                         //   break;
                        }
                    }

                }

            }
            for(i=0;i<n;i++)
            {
               makeedge(0,i+1,1);
           //    makeedge(i+1+n,n*2+1,1);

            }

            for(i=0;i<m;i++)
            {
                makeedge(i+1+n,n+m+1,1);
            }






            maxflow(0,n+m+1);
            printf("Case %d: ",kk1);
            print1(totflow);
        }
        return 0;
    }
    /*
    7 8
    1 2 3
    1 3 1
    2 4 3
    3 4 5
    3 5 4
    4 7 2
    5 6 2
    6 7 3
    1 7
    */
    //4

