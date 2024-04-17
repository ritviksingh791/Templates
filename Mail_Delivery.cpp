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

vi path;

void dfs(vector<set<int>>& adj, int x)
{
    while(!adj[x].empty())
    {
        int y = *adj[x].begin();
        adj[x].erase(y);
        adj[y].erase(x);
        dfs(adj,y);
    }
    path.pb(x+1);
    
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i = 0; i < n; i++)
    {
        if(adj[i].size()%2!=0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    dfs(adj,0);
    if(path.size()!=m+1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
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