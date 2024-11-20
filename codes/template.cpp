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

ll const maxn=5e5+10, mod=1e9+7, INF=1e18, LOG=20, sq=65;

ll poww(ll a, ll b, ll mod) {
 if (b == 0) return 1;
 return 1 * poww(1 * a * a % mod, b / 2, mod) * ((b % 2 == 1) ? a : 1) % mod;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
