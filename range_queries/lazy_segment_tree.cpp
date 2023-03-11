// useful when update operation is to be performed on ranges;

// in solve function : 
//    tree.clear() ; 
//    tree.resize(4*n + 1 , 0) ;
vl tree; 

void build(vl &arr, ll curr, ll l, ll r)
{
    if(l == r)
    {
        tree[curr] = arr[l];
        return ;
    }

    ll m = (l + r) / 2;

    build(arr, curr*2+1, l, m);
    build(arr, curr*2 + 2 , m+1, r);
}

ll query(ll curr, ll tl, ll tr, ll pos)
{
    if(tl == tr)
        return tree[curr];
    ll tm = (tl + tr) / 2;
    if(pos <= tm)
        return tree[curr] + query(curr*2 + 1, tl, tm, pos);
    else 
        return tree[curr] + query(curr*2 + 2, tm+1, tr, pos);
}

void update(ll curr, ll tl, ll tr, ll l , ll r, ll add)
{
    if(tl == l && tr == r){
        tree[curr] += add;
        return ;
    }

    ll tm = (tl + tr) / 2;

    if(r <= tm) {
        update(curr *2 + 1, tl, tm , l , r , add);
        return ;
    }
    if(l > tm) {
        update(curr * 2 + 2, tm+1, tr, l , r , add);
        return ;
    }

    update(curr * 2 + 1, tl, tm , l , tm, add);
    update(curr * 2 + 2, tm+1, tr, tm+1, r, add);

}
