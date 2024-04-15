#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define f(i,a,n) for(long long i = a; i < n; i++)
#define rf(i,a,n) for(long long i = a; i > n; i--)
#define endl "\n"
#define int long long
#define pb push_back
#define eb emplace_back
#define meh {cout<<"NO"<<endl;return;}
#define yay {cout<<"YES"<<endl;return;}
#define ok(t) {cout<<t<<endl;return;}
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define vin(v) for(auto&x:v)cin>>x;
#define vout(v) for (auto x: v)cout<<x<<' ';cout<<endl;
#define pout(x) cout<<x.first<<' '<<x.second<<endl;
#define vpout(v) for (auto x: v)cout<<x.first<<' '<<x.second<<endl;
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

void dfs(vvi & adj, int u, vi& path, vi& out_degree)
{
    while(out_degree[u])
    {
        dfs(adj,adj[u][--out_degree[u]],path,out_degree);
    }
    path.pb(u);
}

void solve()
{
    // Euler Path
    int n,m;
    cin>>n>>m;
    vi in_degree(n+1,0);
    vi out_degree(n+1,0);
    vvi adj(n+1);
    f(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        in_degree[b]++;
        out_degree[a]++;
        adj[a].pb(b);
        // adj[b].pb(a);
    }
    if(in_degree[1]+1!=out_degree[1]||out_degree[n]+1!=in_degree[n])
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for (int i = 2; i < n; i++)
    {
        if(in_degree[i]!=out_degree[i])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    vi path;
    dfs(adj,1,path,out_degree);
    if(sz(path)!=m+1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    reverse(all(path));
    vout(path);

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
