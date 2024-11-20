
bool prime[maxn];

void sieve()
{
	for(ll i=0;i<maxn;i++) prime[i]=1;
	prime[0]=prime[1]=0;
	
	for(ll i=2;i<maxn;i++)
	{
		if(prime[i])
		{
			for(ll j=i*i;j<maxn;j+=i) prime[j]=0;
		}
	}
}
