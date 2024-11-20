void init()
{
    fact[0]=1;
    for(ll i=1;i<maxn;i++) fact[i]=md(fact[i-1]*i);
    inv[maxn-1]=poww(fact[maxn-1], mod-2, mod);
    for(ll i=maxn-2;i>=0;i--) inv[i]=md(inv[i+1]*(i+1));
}

ll nCr(ll n, ll r)
{
    if(r<0 || n<0 || r>n) return 0;
    return fact[n]*inv[n-r]%mod*inv[r]%mod;
}