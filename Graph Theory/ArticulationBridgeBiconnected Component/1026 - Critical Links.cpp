#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

///code copy from cp3 articulation point


#define DFS_WHITE -1
#define DFS_BLACK 1

vi AdjList[100001];
set<ii>ans;
set<ii>::iterator it;
vi dfs_num;
int numCC;


vi dfs_low;
vi articulation_vertex;
vi dfs_parent;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
for (int j = 0; j < AdjList[u].size(); j++) {
int v = AdjList[u][j];
if (dfs_num[v] == DFS_WHITE) {
dfs_parent[v] = u;
if (u == dfsRoot) rootChildren++;

articulationPointAndBridge(v);

if (dfs_low[v] >= dfs_num[u])
articulation_vertex[u] = true;
if (dfs_low[v] > dfs_num[u])
{
int a=u;
int b=v;
if(a>b) swap(a,b);
ii p;
p.first=a;
p.second=b;
ans.insert(p);
}
dfs_low[u] = min(dfs_low[u], dfs_low[v]);
}
else if (v != dfs_parent[u])
dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}

}


int main() {

int t,ts;
scanf("%d",&ts);
for(t=1;t<=ts;t++)
{

int V,ed,a,b;
scanf("%d",&V);

for(int i=0;i<V;i++)
{
scanf("%d (%d)",&a,&ed);
while(ed--)
{
scanf("%d",&b);
AdjList[a].push_back(b);
AdjList[b].push_back(a);
}
}
int l=V;
dfsNumberCounter = 0; dfs_num.assign(l, DFS_WHITE); dfs_low.assign(l, 0);
dfs_parent.assign(l, 0); articulation_vertex.assign(l, 0);

for (int i = 0; i < V; i++)
if (dfs_num[i] == DFS_WHITE) {
dfsRoot = i; rootChildren = 0;
articulationPointAndBridge(i);
articulation_vertex[dfsRoot] = (rootChildren > 1);
}
printf("Case %d:\n",t);
int cn=0;
for(it=ans.begin();it!=ans.end();it++)
{
cn++;
}
printf("%d critical links\n",cn);
for(it=ans.begin();it!=ans.end();it++)
{
int a,b;
ii p=*it;
a=p.first;
b=p.second;
printf("%d - %d\n",a,b);
}



for (int i = 0; i < V; i++)
AdjList[i].clear();

ans.clear();
}
return 0;
}

