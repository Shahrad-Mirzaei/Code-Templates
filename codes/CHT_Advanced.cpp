struct Line {
	mutable ld k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ld x) const { return p < x; }
};
 
struct CHT : multiset<Line, less<>> {
	bool isect(iterator x, iterator y) {
		if(y == end()) return x->p = INF, 0;
		if(x->k == y->k) x->p = x->m > y->m ? INF : -INF;
		else x->p = (y->m - x->m) / (x->k - y->k);
		return x->p >= y->p;
	}
	void add(ld k, ld m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) z = erase(z);
		if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ld query(ld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
} cht;