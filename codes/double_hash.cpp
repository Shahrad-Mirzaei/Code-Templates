ll pw[2][maxn], MOD[2]={1000000007, 998244353};

bool is_prime(ll x)
{
    for(ll i=2;i*i<=x;i++)
        if(x%i==0) return 0;
    return 1;
}

void gen_hash()
{
    for(ll t=0;t<2;t++)
    {
        pw[t][0]=1;
        pw[t][1]=rng()%200+100;
        while(pw[t][1]==pw[t^1][1] || !is_prime(pw[t][1])) pw[t][1]++;
        for(ll i=2;i<maxn;i++) pw[t][i]=(pw[t][i-1]*pw[t][1])%MOD[t];
    }
}

struct Hash{

    ll h[2][maxn];
    void init(string s)
    {
       for(ll t=0;t<2;t++)
       {
           h[t][0]=0;
           for(ll i=1;i<s.size();i++)
               h[t][i]=(h[t][i-1]*pw[t][1]+s[i])%MOD[t];
       }
    }

    pll get(ll l, ll r)
    {
        return{
            (h[0][r]-h[0][l-1]*pw[0][r-l+1]%MOD[0]+MOD[0])%MOD[0],
            (h[1][r]-h[1][l-1]*pw[1][r-l+1]%MOD[1]+MOD[1])%MOD[1]
        };
    }
} H;