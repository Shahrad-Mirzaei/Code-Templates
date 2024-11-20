void build(matrix &mat, ll s)
{
    mat.resize(s);
    for(ll i=0;i<s;i++)
    {
        mat[i].resize(s);
    }
}

matrix operator*(matrix a, matrix b)
{
    matrix c;
    c.resize(a.size());
    for(ll i=0;i<c.size();i++) c[i].resize(b.size());
 
    for(ll i=0;i<a.size();i++)
    {
        for(ll j=0;j<b.size();j++)
        {
            for(ll w=0;w<a[i].size();w++)
            {
                c[i][j]=md(c[i][j]+(a[i][w]*b[w][j]));
            }
        }
    }
    return c;
}
 
matrix mat_pow(matrix a, ll t)
{
    matrix ans;
    build(ans, a.size());
    for(ll i=0;i<a.size();i++) ans[i][i]=1;
 
    for(;t;t/=2, a=a*a)
    {
        if(t&1) ans=ans*a;
    }
    return ans;
}