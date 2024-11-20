ll fen[maxn];

ll Get(ll i)
{
	ll s=0;
	for(;i;i-=(-i)&i) s+=fen[i];
	return s;
}

void Upd(ll i, ll v)
{
	for(;i<maxn;i+=(-i)&i) fen[i]+=v;
}