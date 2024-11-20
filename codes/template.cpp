#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define md(a) (a%mod+mod)%mod
#define pb push_back
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<ll, ll> pll;

ll const maxn=2e5+10, mod=1e9+7, MOD=10000000019, INF=1e18, LOG=30;

ll poww(ll a, ll b, ll m)
{
	if(b==0) return 1;
	return 1*poww(1*a*a%m, b/2, m)*((b&1)?a:1)%m;
}


int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
}
