void dfs(ll v)
{
    vis[v]=1;
    for(auto u:g[v])
    {
        if(!vis[u.F]) dfs(u.F);
    }
    top.pb(v);
}
 
void back_dfs(ll v)
{
    col[v]=c;
    com[c].pb(v);
    for(ll u:gr[v])
    {
        if(!col[u])
            back_dfs(u);
    }
 
}
 
void SCC()
{
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    reverse(top.begin(), top.end());
    for(ll i:top)
    {
        if(!col[i])
        {
            c++;
            back_dfs(i);
        }
    }
}