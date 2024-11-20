struct TWOSAT {
	int n;
	vector<int> G[maxn*8],GP[maxn*8];
	int comp[maxn*8];
	bool mark[maxn*8];
	vector<int> topol;
	int mx=maxn*8-1;
	
	void clear() {
		for(int i = 0; i<=min(mx+10,maxn*8-1);i++) {
			G[i].clear();
			GP[i].clear();
			comp[i] = -1;
			mark[i] = false;
		}
		topol.clear();
		mx = 1;
	}
	
	void add(int a,bool na,int b,bool nb) {
		a = a*2 ^ na;
		b = b*2 ^ nb;
		G[a^1].pb(b);
		G[b^1].pb(a);
		GP[b].pb(a^1);
		GP[a].pb(b^1);
		mx = max({mx,a,b,a^1,b^1});
	}
	
	void dfs1(int v) {
		mark[v] = true;
		for(int u : G[v]) if(!mark[u]) dfs1(u);
		topol.pb(v);
	}
	
	void dfs2(int v,int c) {
		comp[v] = c;
		for(int u : GP[v]) if(comp[u] == -1) dfs2(u,c);
	}
	
	bool solve() {
		for(int i = 0; i<=mx ; i++) if(!mark[i]) {
			dfs1(i);
		}
		reverse(all(topol));
		int x = 0;
		for(int v : topol) {
			if(comp[v] == -1) {
				dfs2(v,x++);
			}
		}
		for(int i = 1; i <= mx; i += 2) {
			if(comp[i] == comp[i-1])
				return false;
		}
		return true;
	}
} sat;