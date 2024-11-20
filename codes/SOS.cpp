for(ll i=0;i<(1<<maxn);i++)
	dp[i]=A[i];
for(ll i=1;i<maxn;i++) for(ll mask=0;mask<(1<<maxn);mask++){
	if(mask&(1<<i))
		dp[mask]+=dp[mask^(1<<i)];
}