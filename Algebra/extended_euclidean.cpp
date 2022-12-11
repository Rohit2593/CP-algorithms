// let g be the gcd of a and b 
// after performing the extended euclidean algorithm, we will get the values of x and y such that a.x + b.y = g 
// if g == 1, then 
// -> (a.x) mod y = 1 mod y    ( ie. modular inverse of a modulo y is x)
// -> (b.y) mod x = 1 mod x 

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
