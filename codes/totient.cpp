// calc phi(n) in O(SQ)

ll phi(ll n)
{
	ll res=n;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0) n/=i;
			res-=res/i;
		}
	}
	if(n>1) res-=res/n;
	return res;
}