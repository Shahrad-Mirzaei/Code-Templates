// CSES -> Path Queries 2

#include <bits/stdc++.h>
 
/*
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
*/
 
using namespace std;
 
/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/
 
#define F first
#define S second
#define pb push_back
#define FIO freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define md(a) ((a%mod+mod)%mod)
#define all(a) a.begin(), a.end()
#define MP make_pair
#define lc (id<<1)
#define rc (lc|1)
#define mid (l+r)/2
#define kill(a) cout << a << "\n", exit(0)
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef long long ll;
typedef long double ld;
typedef vector<vector<ll>> matrix;
mt19937_64  rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll const maxn=2e5+10, mod=1e9+7, INF=1e18, LOG=20, sq=65;
 
ll poww(ll a, ll b, ll mod) {
 if (b == 0) return 1;
 return 1 * poww(1 * a * a % mod, b / 2, mod) * ((b % 2 == 1) ? a : 1) % mod;
}
 
int n, q, seg[maxn<<2], timer, hd[maxn], st[maxn], val[maxn], par[maxn], sz[maxn];
vector<int> g[maxn];
 
inline void Upd(int p, int x, int l=1, int r=n+1, int id=1)
{
    if(l==r-1)
    {
        seg[id]=x;
        return;
    }
 
    if(p<mid) Upd(p, x, l, mid, lc);
    else Upd(p, x, mid, r, rc);
    seg[id]=max(seg[lc], seg[rc]);
}
 
inline int Get(int s, int e, int l=1, int r=n+1, int id=1)
{
    if(l>=e || r<=s) return 0;
    if(s<=l && r<=e) return seg[id];
    return max(Get(s, e, l, mid, lc), Get(s, e, mid, r, rc));
}
 
inline void pre_dfs(int v, int p=0)
{
    par[v]=p;
    sz[v]=1;
    for(int u:g[v])
    {
        if(u!=p)
        {
            pre_dfs(u, v);
            sz[v]+=sz[u];
        }
    }
}
 
inline void dfs_hld(int v, int p=0)
{
    if(!hd[v]) hd[v]=v;
    st[v]=++timer;
    if(sz[v]==1) return;
    int hch, hsz=0;
    for(int u:g[v])
    {
        if(u!=p && sz[u]>hsz)
        {
            hch=u;
            hsz=sz[u];
        }
    }
 
    hd[hch]=hd[v];
    dfs_hld(hch, v);
    for(int u:g[v])
    {
        if(u!=p && hch!=u) dfs_hld(u, v);
    }
}
 
inline int Get_path(int v, int u)
{
    int ans=0;
    while(hd[v]!=hd[u])
    {
        if(st[v]<st[u]) swap(v, u);
        ans=max(ans, Get(st[hd[v]], st[v]+1));
        v=par[hd[v]];
    }
    if(st[v]<st[u]) swap(v, u);
    return max(ans, Get(st[u], st[v]+1));
}
 
int main() 
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++)
    {
        int v, u;
        cin>>v>>u;
        g[v].pb(u);
        g[u].pb(v);
    }
 
    pre_dfs(1);
    dfs_hld(1);
 
    for(int i=1;i<=n;i++) Upd(st[i], val[i]);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int s, x;
            cin>>s>>x;
            Upd(st[s], x);
        }
        else
        {
            int v, u;
            cin>>v>>u;
            cout<<Get_path(v, u)<<" ";
        }
    }
    cout<<"\n";
 
    return 0;
 
}
