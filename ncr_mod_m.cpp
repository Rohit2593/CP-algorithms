// only works when md is a prime number. 

const ll md = 1000000007;

ll pw(ll a, ll b){
    if(b==0)
        return 1;
    ll ans = pw(a, b/2);
    ans *= ans;
    ans %= md;
    if(b%2){
        ans *= a;
        ans %= md;
    }
    return ans;
}

// ( (a / b) % md )  is equivalent to ( a * inv(b) ) % md

ll inv(ll n)
{
	return pw(n , md - 2);
}

ll nCr_mod_m(ll n , ll r)
{
	if(r > n-r) r = n-r;

	ll ans = 1;

	for(ll i = 1; i<=r; i++)
	{
		ans *= (n - r + i);
		ans %= md;
		ans *= inv(i);
		ans %= md;
	}

	return ans;
}
