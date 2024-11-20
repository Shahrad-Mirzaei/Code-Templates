ll K, lps[maxn];

void KMP(string S, ll len)
{
    lps[0]=-1;
    K=0;
    for(ll i=2;i<=len;i++)
    {
        while(K!=-1 && S[i]!=S[K+1]) K=lps[K];
        lps[i]=++K;
    }
}