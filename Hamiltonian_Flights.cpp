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

int n;
vector<vector<int>> adj;
int dp [20][1<<20];

int dfs(int u, int mask)
{
    if(__builtin_popcount(mask)==n)
    {
        return 1;   
    }
    else if(u == n-1)
    {
        return 0;
    }
    if(dp[u][mask]!=-1)
    {
        return dp[u][mask];
    }
    int res = 0;
    for(auto x:adj[u])
    {
        if(mask&(1<<x))
        {
            continue;
        }
        res+=dfs(x,mask|(1<<x));
        res%=MOD;
    }
    dp[u][mask]=res;
    return res;
}

void solve()
{
    // CSES Problem Set: Hamiltoniam Flights
    // TC O(m*(2^n))
    int m;
    cin>>n>>m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;    
        adj[a].push_back(b);
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,1)<<endl;

    
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
