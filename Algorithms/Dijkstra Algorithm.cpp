/*
Used in finding the shortest path from a source vertex to any other vertex of the graph 

Intuition-
Similar to Prims algorithm
Prims Algorithm is similar to bfs except that we sort the vertices and the weights in the priority queue
Hence we get the MSP
In Dijkstra we do similar thing like Prims but also store the distance of all nodes from the source in a dist array.
As we keeping pushing the nodes into the priority queue , if two same nodes are present in the priority queue , then first one to be removed is the one with minimum weight due to internal sorting.
If we currently meet a node and if that node is not previously present in the pq(in the sense its already visited) we dont push it again because the minimum path has already been obtained for that node.

Disadvantages-
It is similar to bfs in the sense once all the neighbours are pushed into the queue and sorted and pushed out then it assumes that adding any further weights will not change the minimal path.
But their could be a negative edge in the next level which gives the least cost as well.

Time Complexity - 
O(Elog(V)) .Going through and pushing all the vertices and sorting them.

Space Complexity-
O(V+E)

*/

//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set

//#define        ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define        fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define        f first
#define        s second
#define        pb push_back
#define        eb emplace_back
//#define        pii pair<int,int>
#define        pli pair<long,int>
#define        pil pair<int,long>
#define        pll pair<long,long>
#define        mp  make_pair
#define        forn(i,n) for(int i=0;i<n;++i)
#define        show(b) for(auto const&x: b) cout<<x<<" "
#define        sshow(b) for(auto x:b) cout<<x<<" "
#define        fix(b,val)   memset(b,val,sizeof(b))
#define        pill(b,n,v)  fill(b,b+n,v)
#define        itn          int
#define        w(t)     int t;cin>>t;while(t--)
#define        mx(a,b,c) max(a,max(b,c))
#define        mn(a,b,c) min(a,min(b,c))
#define        intmax    INT_MAX
#define        intmin    INT_MIN


typedef long long ll;
typedef long double LD;
typedef unsigned long long int LL;
typedef pair<int,int> pii;
const int N=1e5+5;
const int mod=1e9+7;
//mt19937 rnd(time(NULL));

//////////////////////////////////////////////////////////////
vector<vector<pii>> adj;
vector<bool>vis;
vector<int>dist;
vector<int>parent;

void rf()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void Dijkstra(int n)
{
    dist[n] = 0;
    multiset<pii> st;                 //multiset does the same job as a priority queue
    st.insert({0,n});
   /// vis[n] = true;
    while(!st.empty())
    {
        pii top= *st.begin();
        int vertex = top.second;
        int cost = top.first;
        st.erase(st.begin());
        if(vis[vertex])
            continue;
        vis[vertex] = true;
        for(auto x:adj[vertex])
        {
            if(((dist[vertex] + x.f) < dist[x.s]) && (vis[x.s]==false))    //If the (distance of the parent + edge length ) is lesser than the current distance of the node then update it.
            {
                dist[x.s] = dist[vertex] + x.f;
                parent[x.s] = vertex;                 //Store its parent
                st.insert({dist[x.s],x.s}); 
            }
        }
    }
}

int32_t main()
{
    fast;
    rf();
    int n,m;
    int a,b,cost;
    cin>>n>>m;
    adj = vector<vector<pii>>(n+1);
    vis = vector<bool>(n+1,false);
    dist = vector<int>(n+1,intmax);
    parent = vector<int>(n+1,-1);
    for(int i=0;i<m;++i)
    {
        cin>>a>>b>>cost;
        adj[a].pb({cost,b});
        adj[b].pb({cost,a});
    }
    Dijkstra(1);
    for(int i=2;i<=n;++i)        //Outputting
    {
        cout<<dist[i]<<"\n";
        cout<<"path ";
        int j=i;
        vector<int> vec;
        vec.pb(i);
        while(parent[i] != -1)
        {
            vec.pb(parent[i]);
            i = parent[i];
        }
        reverse(vec.begin(),vec.end());
        show(vec);
        cout<<"\n";
        i=j;
    }
}


