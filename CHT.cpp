struct CHT{
 
    vector<pair<ll , pll>> L;
    
    ll Intersection(pll A , pll B){
        ll x = A.S - B.S , y = B.F - A.F;
        return x / y + (x % y > 0);
    }
     
    void Add(ll a , ll b){
        ll p = 0;
        while(L.size()){
            p = Intersection(L.back().S , pll(a , b));
            p = max(L.back().F , p);
            if(p <= L.back().F){
                L.pop_back();
                continue;
            }
            break;
        }
        L.push_back({p , {a , b}});
    }
     
    pll Get(ll x){
        if(x == 0)  return {0 , 0};
        ll l = 0 , r = L.size();
        while(r - l > 1){
            if(L[mid].F * L[mid].S.F + L[mid].S.S <= x) l = mid;
            else r = mid;
        }
        ll diff = x - L[l].F * L[l].S.F - L[l].S.S , p = L[l].F + (diff + L[l].S.F - 1) / L[l].S.F;
        if(r != L.size() && p >= L[r].F) return {L[r].F * L[r].S.F + L[r].S.S , L[r].F};
        return {p * L[l].S.F + L[l].S.S , p};
    }
};
 
CHT cht;
