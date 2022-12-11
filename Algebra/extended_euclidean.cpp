ll extended_euclidean(ll a, ll b, ll &x, ll &y) {
    if(b > a) 
        return extended_euclidean(b, a, y, x) ;
    if(b == 0) {
        x = 1 ;
        y = 0; 
        return a ;
    }

    ll x1, y1 ;
    ll g = extended_euclidean(b, a % b, x1, y1) ;

    x = y1 ;
    y = x1 - y1 * (a / b) ;

    return g ;
}
