#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define f(i,a,n) for(long long i = a; i < n; i++)
#define rf(i,a,n) for(long long i = a; i > n; i--)
#define endl "\n"
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define meh {cout<<"NO"<<endl;return;}
#define yay {cout<<"YES"<<endl;return;}
#define ok(t) {cout<<t<<endl;return;}
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vin(v) for(auto&x:v)cin>>x;
#define vout(v) for (auto x: v)cout<<x<<' ';cout<<endl;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;
typedef set<char> sc;

const int MAXN = 200100;
const int MOD = 1000000007;
const int imax = LLONG_MAX;
const int imin = LLONG_MIN;

int n,m;

typedef struct edge
{
    int start;
    int end;
    int weight;
} edge;

vector<edge> adj;
vvi adj1;
vvi adj2;
vb vis1;
vb vis2;

int dfs1(int node)
{
    vis1[node] = 1;
    for(auto x: adj1[node])
    {
        if(!vis1[x])
        {
            dfs1(x);
        }
    }
    return 0;
}

int dfs2(int node)
{
    vis2[node] = 1;
    for(auto x: adj2[node])
    {
        if(!vis2[x])
        {
            dfs2(x);
        }
    }
    return 0;
}

void solve()
{

    // Belman Ford
    // TC: O(n*m)
  // CSES Problem Set: High Score
    cin>>n>>m;
    adj.resize(m);
    adj1.resize(n+1);
    adj2.resize(n+1);
    vis1.resize(n+1);
    vis2.resize(n+1);
    for (int i = 0; i < n+1; i++)
    {
        vis1[i]=0;
        vis2[i]=0;
    }
    vi dist(n+1,imin);
    for (int i = 0; i < m; i++)
    {
        cin>>adj[i].start>>adj[i].end>>adj[i].weight;
        adj1[adj[i].start].pb(adj[i].end);
        adj2[adj[i].end].pb(adj[i].start); 
    }

    dfs1(1);
    dfs2(n);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int num_changed = 0;
        for (int j = 0; j < m; j++)
        {
            if(dist[adj[j].start] == imin)
            {
                continue;
            } 
            else if(dist[adj[j].end]==imin)
            {
                dist[adj[j].end] = dist[adj[j].start] + adj[j].weight;
                num_changed++;

                if(i==n-1&&vis1[adj[j].end]&&vis2[adj[j].end])
                {
                    cout<<-1<<endl;
                    return;
                }
            }
            else if(dist[adj[j].start]+adj[j].weight>dist[adj[j].end])
            {
                dist[adj[j].end] = dist[adj[j].start]+adj[j].weight;
                num_changed++;
                if(i==n-1&&vis1[adj[j].end]&&vis2[adj[j].end])
                {
                    cout<<-1<<endl;
                    return;
                }
            }

        }
        // vout(dist);
    }
    cout<<dist[n]<<endl;
    
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++)
    {
        solve();
    }
    return 0;
}
