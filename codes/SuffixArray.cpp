int n, Rank[maxn][LOG], P[maxn], pw;
int lcp[maxn];
string S;
 
bool cmp(int x, int y){
	if (Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
	if (max(x, y)+(1<<(pw-1))>n) return x>y;
	return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}
 
void BuildSuffixArray(){
	for (int i=1; i<=n; i++) Rank[i][0]=S[i-1], P[i]=i;
	for (pw=1; pw<LOG; pw++){
		sort(P+1, P+n+1, cmp);
		Rank[P[1]][pw]=1;
		for (int i=2; i<=n; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp(P[i-1], P[i]);
	}
}
 
int Lcp(int x, int y){
	int res=0;
	for (int i=LOG-1; i>=0; i--) if (Rank[x][i]==Rank[y][i]){
		x+=(1<<i);
		y+=(1<<i);
		res|=(1<<i);
	}
	return res;
}