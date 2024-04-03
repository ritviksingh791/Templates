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
    int m;
    cin>>m;
    if(m==1)
    {
        cout<<"10"<<endl;
        return;
    }
    int n =  1<<m-1;
    vi in_degree(n,0);
    vi out_degree(n,0);
    vvi adj(n);
    for (int i = 0; i < n; i++)
    {
        int curr = i;
        int next = (curr<<1)&(n-1);
        adj[curr].pb(next);
        out_degree[curr]++;
        in_degree[next]++;
        next++;
        adj[curr].pb(next);
        out_degree[curr]++;
        in_degree[next]++;
    }
    vi path;
    dfs(adj,0,path,out_degree);
    reverse(all(path));    
    for (int i = 0; i < m-2; i++)
    {
        cout<<"0";
    }
    
    for (int i = 0; i < path.size(); i++)
    {
        cout<<bitset<32>(path[i]).to_string().substr(32-m+(m-1));
    }
    cout<<endl;
    

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