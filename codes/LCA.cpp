void set_par()
{
    for(ll i=1;i<LOG;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            par[i][j]=par[i-1][par[i-1][j]];
        }
    }
}

ll Get_par(ll v, ll r)
{
    for(ll i=LOG-1;i>=0;i--)
    {
        if(r&(1ll<<i))
        {
            v=par[i][v];
        }
    }
    return v;
}

ll LCA(ll v, ll u)
{
    if(h[v]<h[u]) swap(v, u);
    v=Get_par(v, h[v]-h[u]);
    if(v==u) return v;

    for(ll i=LOG-1;i>=0;i--)
    {
        if(par[i][v]!=par[i][u])
        {
            v=par[i][v];
            u=par[i][u];
        }
    }
    return par[0][v];
}