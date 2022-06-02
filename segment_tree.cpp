// initialize tree as : vl tree(4*n + 1) where n is the size of array;

void build(vl &tree, vl &arr, ll curr, ll l, ll r)
{
    if(l == r) {
        tree[curr] = arr[l];
        return ;
    }

    ll m = (l + r) / 2;

    build(tree, arr, curr*2+1, l, m);
    build(tree, arr, curr*2+2, m+1, r);

    tree[curr] = tree[curr*2+1] + tree[curr*2 + 2];
}    

ll query(vl &tree, ll curr, ll tl, ll tr, ll l , ll r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return tree[curr];

    ll tm = (tl + tr) / 2;

    if(r <= tm)
        return query(tree, curr*2 + 1, tl, tm, l , r);
    if(l > tm)
        return query(tree, curr*2 + 2 , tm+1, tr, l , r);

    ll lp = query(tree, curr*2 + 1, tl, tm, l , tm);
    ll rp = query(tree, curr*2 + 2 , tm+1, tr, tm+1 , r);

    return lp + rp;
}

void update(vl &tree, ll curr, ll tl, ll tr, ll pos, ll new_ele)
{
    if(tl == tr) {
        tree[curr] = new_ele;
        return ;
    }

    ll tm = (tl + tr) / 2;
    if(pos > tm)
        update(tree, curr*2 + 2, tm+1, tr, pos, new_ele);
    else 
        update(tree, curr*2 + 1, tl, tm , pos, new_ele);

    tree[curr] = tree[curr*2+1] + tree[curr*2+2];
}
