    //accepted

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
    VI adj[mo];//input
    int w[mo][mo];//input
    int w1[mo][mo];
    VI sinklist;//adj[sink]
    bool col[mo];
    int par[mo];//par and col for parent and visited respectively
    int totflow,flow;//flow related variables.(not needed normally)

    struct point{
       double x1,y1;
       int num;

    }pp[102];

    double sq(double x1,double y1,double x2,double y2)
    {
        return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }

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
            flow=min(flow,w1[prev][next]);
            next=prev;
        }
        //printf("fds");
        next=sink;
        while(par[next]>-1)
        {
            prev=par[next];
            w1[prev][next]-=flow;
            w1[next][prev]+=flow;
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
                if(!col[next]&&w1[prev][next]>0)
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
                if(!col[u] || w1[u][sink]<=0) continue;
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
        int n;
        double D;
        int e;
        int t,yy;
        scanf("%d",&t);
        for(int kk1=1;kk1<=t;kk1++){

            int i;
            int c,d;
            double a,b;
            scanf("%d",&n);
            scanf("%lf",&D);
            D=D*D;

            yy=n+n+2;

            mem(w,0);
            fr(i,0,yy)
             adj[i].clear();
             int tot=0;
            fr(i,1,n)
            {
            //    cin>>a>>b>>c>>d;
                                                    //x y num.of.pen limit
                 scanf("%lf %lf %d %d",&a,&b,&c,&d);
                pp[i].x1=a;
                pp[i].y1=b;
                pp[i].num=c;
                makeedge(0,i,c);
                tot=tot+c;
                makeedge(i,i+n,d);
            }
            double x1,y1,x2,y2;
            for(i=1;i<=n;i++)
            {
                x1=pp[i].x1;
                y1=pp[i].y1;
                for(int j=i+1;j<=n;j++)
                {
                    x2=pp[j].x1;
                    y2=pp[j].y1;
                    double len;
                    len=sq(x1,y1,x2,y2);
                    if(len<=D)
                    {
                        makeedge(i+n,j,100000);
                        makeedge(j+n,i,100000);
                    }

                }
            }

            //int source,sink;
            //cin>>source>>sink;
            int lop,lop2,lop3;
            int j,k;

            bool flag=false;
            vector<int>ans;

            for(i=1;i<=n;i++)
            {
              lop=w[i][i+n];
              lop2=w[0][i];
              w[i][i+n]=0;
              w[0][i]=0;

               lop3=w[i+n][i];
               w[i+n][i]=0;
                for(int pp1=0;pp1<=2*n+1;pp1++)
                {
                    for(int pp2=0;pp2<=2*n+1;pp2++)
                    {
                        w1[pp1][pp2]=w[pp1][pp2];
                    }
                }

                maxflow(0,i);
                 totflow=totflow+pp[i].num;
            //     cout<<totflow<<endl;

                if(totflow>=tot)
                {
                    flag=true;
                    ans.push_back(i);
                }
               w[i][i+n]=lop;
                w[0][i]=lop2;
                w[i+n][i]=lop3;
       //         int sz;
        //        sz=adj[i].size();
       //         for(k=sz-1;k>=0;k--)
        //        {
        //            if(adj[i][k]==0||adj[i][k]==i+n)
        //            {
         //               break;
         //           }
         //           else
         //           {
          //              adj[i].pop_back();
           //         }
            //    }


            }
         //   maxflow(source,sink);
         //   print1(totflow);

      //     cout<<ans.size()<<endl;

          printf("Case %d: ",kk1);

          if(ans.size()==0)
          {
             // cout<<"-1"<<endl;
               printf("-1\n");
          }
          else
          {
              for(i=0;i<ans.size()-1;i++)
              {
               //   cout<<ans[i]-1<<" ";
                 printf("%d ",ans[i]-1);
              }
          //    cout<<ans[ans.size()-1]-1<<endl;
              printf("%d\n",ans[ans.size()-1]-1);
          }
       //   cout<<endl;

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
    //Case 1: 1 2 4


