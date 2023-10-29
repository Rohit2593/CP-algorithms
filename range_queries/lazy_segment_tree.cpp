struct node{
    ll val = 0;
    ll lazy = 0;

    node(){
        val = 0;
        lazy = 0;
    }

    node(ll v){
        val = v;
        lazy = 0;
    }

    void merge(node &n1, node &n2){
        val = n1.val + n2.val;
    }
};

class LazySegTree{
public:
    ll n;
    vector<node> tree;
    vector<ll> arr;

    LazySegTree(ll n, vector<ll> arr){
        this->n = n;
        this->arr = arr;
        tree.resize(4*n + 10);

        fill(tree.begin(), tree.end(), node());
    }

    void build(ll ind, ll tl, ll tr){
        if(tl == tr){
            tree[ind].val = arr[tl];
            return;
        }

        ll tm = (tl + tr) / 2;

        build(2*ind + 1, tl, tm);
        build(2*ind + 2, tm+1, tr);

        tree[ind].merge(tree[2*ind + 1], tree[2*ind + 2]);
    }

    void performUpdate(ll ind, ll tl, ll tr, ll upd){
        tree[ind].val += (tr - tl + 1ll) * upd;

        if(tr != tl){
            tree[2*ind + 1].lazy += upd;
            tree[2*ind + 2].lazy += upd;
        }
    }
            
    ll query(ll ind, ll tl, ll tr, ll l, ll r){
        if(tl > tr || tl > r || tr < l)
            return 0;

        performUpdate(ind, tl, tr, tree[ind].lazy);
        tree[ind].lazy = 0;

        if(tl >= l && tr <= r)
            return tree[ind].val;

        ll tm = (tl + tr) / 2;

        ll v1 = query(2*ind + 1, tl, tm, l, r);
        ll v2 = query(2*ind + 2, tm + 1, tr, l, r);

        node temp(0);
        node left(v1);
        node right(v2);

        temp.merge(left, right);

        return temp.val;
    }

    void update(ll ind, ll tl, ll tr, ll l, ll r, ll val){
        performUpdate(ind, tl, tr, tree[ind].lazy);
        tree[ind].lazy = 0;

        if(tl > tr || tl > r || tr < l)
            return; 

        if(tl >= l && tr <= r){
            performUpdate(ind, tl, tr, val);
            return;
        }

        ll tm = (tl + tr) / 2;
        update(2*ind + 1, tl, tm, l, r, val);
        update(2*ind + 2, tm+1, tr, l, r, val);

        tree[ind].merge(tree[2*ind + 1], tree[2*ind + 2]);
    }
};
