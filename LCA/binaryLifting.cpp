vector<int> tin(n), tout(n) ;
vector<vector<int>> ancestors(n, vector<int>(20, -1)) ;

int timer = 0 ;
function<void(int , int)> dfs = [&](int curr, int par) {
    ancestors[curr][0] = par ;
    tin[curr] = timer++;
    for(auto &i : tree[curr]) {
        if(i != par) {
            dfs(i, curr) ;
        }
    }
    tout[curr] = timer++;
} ;

dfs(0, -1) ;

// binary lifting - helps us to calculate any ancestor in log(n) time 
for(int i = 1; i<20; i++) {
    for(int j = 0; j<n; j++) {
        int p = ancestors[j][i-1] ;
        if(p != -1)
            ancestors[j][i] = ancestors[p][i-1] ;
    }
}

function<bool(int, int)> isParent = [&](int x, int y) {
    return (tin[x] <= tin[y] && tout[x] >= tout[y]) ;
} ;

function<int(int, int)> getLca = [&](int x, int y) {
    if(isParent(x, y))
        return x ;
    if(isParent(y, x))
        return y ;

    for(int i = 19; i>=0; i--) {
        if(ancestors[x][i] != -1 && (!isParent(ancestors[x][i], y)))
            x = ancestors[x][i] ; 
    }

    return ancestors[x][0] ;
} ;
